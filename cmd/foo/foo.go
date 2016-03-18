package main

import (
	"encoding/binary"
	"encoding/hex"
	"flag"
	"fmt"
	"io"
	"io/ioutil"
	"log"
	"os"
	"path/filepath"
	"strings"
	"text/template"

	"github.com/kr/pretty"
	"github.com/mewkiz/pkg/errutil"
	"github.com/mewkiz/pkg/pathutil"
	"github.com/mewrev/pe"
)

func usage() {
	const use = `
Usage: foo [OPTION]... FILE.exe

Flags:`
	fmt.Println(use[1:])
	flag.PrintDefaults()
}

// Command line flags.
var (
	// verbose specifies whether verbose output is enabled.
	verbose bool
)

func init() {
	// Parse command line parameters.
	flag.BoolVar(&verbose, "v", false, "Verbose output.")
	flag.Usage = usage
	flag.Parse()

	// Fix duplicate source files.
	fixDupFiles(".text", textFiles)
	fixDupFiles(".rdata", rdataFiles)
	fixDupFiles(".data", dataFiles)
	fixDupFiles(".bss", bssFiles)
}

func main() {
	for _, path := range flag.Args() {
		if err := dump(path); err != nil {
			log.Fatal(err)
		}
	}
}

func dump(exePath string) error {
	// Parse PE file.
	file, err := pe.Open(exePath)
	if err != nil {
		return errutil.Err(err)
	}
	defer file.Close()

	// Parse all headers of the PE file.
	if err := file.Parse(); err != nil {
		return errutil.Err(err)
	}

	// Create directory based on binary name.
	baseDir := pathutil.FileName(exePath)
	if err := os.MkdirAll(baseDir, 0755); err != nil {
		return errutil.Err(err)
	}

	// Access pre-parsed DOS header.
	dosHdr, _ := file.DOSHeader()
	if verbose {
		fmt.Println("=== [ DOS Header ] ===")
		fmt.Println()
		pretty.Println(dosHdr)
		fmt.Println()
	}

	// Access pre-parsed DOS Stub.
	dosStub, _ := file.DOSStub()
	if verbose {
		fmt.Println("=== [ DOS Stub ] ===")
		fmt.Println()
		fmt.Println(hex.Dump(dosStub))
		fmt.Println()
	}

	// Access pre-parsed file header.
	fileHdr, _ := file.FileHeader()
	if verbose {
		fmt.Println("=== [ File Header ] ===")
		fmt.Println()
		pretty.Println(fileHdr)
		fmt.Println()
	}

	// Access pre-parsed optional header.
	optHdr, _ := file.OptHeader()
	if verbose {
		fmt.Println("=== [ Optional Header ] ===")
		fmt.Println()
		pretty.Println(optHdr)
		fmt.Println()
	}

	sectHdrs, _ := file.SectHeaders()
	if verbose {
		fmt.Println("=== [ Section Headers ] ===")
		fmt.Println()
		for _, sectHdr := range sectHdrs {
			fmt.Printf("--- [ Section Header %q ] ---\n", stringFromSZ(sectHdr.Name[:]))
			fmt.Println()
			pretty.Println(sectHdr)
			fmt.Println()
		}
	}

	// Parse sections.
	if verbose {
		fmt.Println("=== [ Sections ] ===")
		fmt.Println()
	}
	binPaths := []string{"pe-hdr.bin"}
	for _, sectHdr := range sectHdrs {
		data, err := file.Section(sectHdr)
		if err != nil {
			return errutil.Err(err)
		}
		sectName := stringFromSZ(sectHdr.Name[:])

		if verbose {
			fmt.Printf("--- [ Section %q ] ---\n", sectName)
			fmt.Println()
			fmt.Println(hex.Dump(data))
			fmt.Println()
		}

		// Dump section.
		var files []*SourceFile
		switch sectName {
		case ".text":
			files = textFiles
		case ".rdata":
			files = rdataFiles
		case ".data":
			files = dataFiles
		case ".rsrc":
			// No source file mapping.
		}
		if files == nil {
			if err := dumpSection(baseDir, sectName, data); err != nil {
				return errutil.Err(err)
			}
		} else {
			sectBase := uint64(optHdr.ImageBase + sectHdr.RelAddr)
			if err := dumpSectionFiles(baseDir, sectName, data, sectBase, files, int(optHdr.FileAlign)); err != nil {
				return errutil.Err(err)
			}
		}
		binPath := fmt.Sprintf("%s.bin", strings.Replace(sectName, ".", "_", -1))
		binPaths = append(binPaths, binPath)
	}

	// Dump main assembly file.
	mainPath := filepath.Join(baseDir, "main.asm")
	if err := dumpIncBin(mainPath, binPaths); err != nil {
		return errutil.Err(err)
	}

	// Dump PE header.
	if err := dumpPEHeader(baseDir, dosHdr, dosStub, fileHdr, optHdr, sectHdrs); err != nil {
		return errutil.Err(err)
	}

	return nil
}

// dumpSectionFiles stores the section data to dedicated source files within the
// given directory.
func dumpSectionFiles(baseDir, sectName string, data []byte, sectBase uint64, files []*SourceFile, align int) error {
	subDir := strings.Replace(sectName, ".", "_", -1)
	dir := filepath.Join(baseDir, subDir)
	if err := os.MkdirAll(dir, 0755); err != nil {
		return errutil.Err(err)
	}

	if sectBase != files[0].Start {
		log.Fatalf("sectBase 0x%06X != 0x%06X files[0].Start", sectBase, files[0].Start)
	}

	// Ensure that source file address ranges are contained within the section
	// contents.
	data = data[0:len(data):len(data)]

	// Dump section partitioned into source files.
	var binPaths []string
	for _, file := range files {
		binName := fmt.Sprintf("%s.bin", file.Name)
		path := filepath.Join(dir, binName)
		start := file.Start - sectBase
		end := file.End + 1 - sectBase
		if int(end) > len(data) {
			end = uint64(len(data))
		}
		buf := data[start:end]
		if err := ioutil.WriteFile(path, buf, 0644); err != nil {
			return errutil.Err(err)
		}
		binPath := filepath.Join(subDir, binName)
		binPaths = append(binPaths, binPath)
	}

	// Dump padding file.
	var dataLen uint64 = files[len(files)-1].End + 1 - sectBase
	rem := int(dataLen) % align
	if rem != 0 {
		rem = align - rem
		pad := make([]byte, rem)
		binName := "__padding.bin"
		path := filepath.Join(dir, binName)
		if err := ioutil.WriteFile(path, pad, 0644); err != nil {
			return errutil.Err(err)
		}
		binPath := filepath.Join(subDir, binName)
		binPaths = append(binPaths, binPath)
	}

	// Dump section Assembly file.
	asmName := fmt.Sprintf("%s.asm", subDir)
	asmPath := filepath.Join(baseDir, asmName)
	if err := dumpIncBin(asmPath, binPaths); err != nil {
		return errutil.Err(err)
	}

	return nil
}

// dumpSection stores the section data to a file within the given directory.
func dumpSection(baseDir, sectName string, data []byte) error {
	fileName := fmt.Sprintf("%s.bin", strings.Replace(sectName, ".", "_", -1))
	path := filepath.Join(baseDir, fileName)
	if err := ioutil.WriteFile(path, data, 0644); err != nil {
		return errutil.Err(err)
	}
	return nil
}

// dumpPEHeader stores the PE header to a file within the given directory.
func dumpPEHeader(baseDir string, dosHdr *pe.DOSHeader, dosStub []byte, fileHdr *pe.FileHeader, optHdr *pe.OptHeader, sectHdrs []*pe.SectHeader) error {
	// Create output file.
	path := filepath.Join(baseDir, "pe-hdr.bin")
	fw, err := os.Create(path)
	if err != nil {
		return errutil.Err(err)
	}
	// Wrap the writer in a padding writer which keeps track of file alignment.
	pw := NewPadWriter(fw, int(optHdr.FileAlign))
	defer pw.Close()

	// Dump DOS header.
	if _, err := pw.Write([]byte{'M', 'Z'}); err != nil {
		return errutil.Err(err)
	}
	if err := binary.Write(pw, binary.LittleEndian, dosHdr); err != nil {
		return errutil.Err(err)
	}

	// Dump DOS stub.
	if _, err := pw.Write(dosStub); err != nil {
		return errutil.Err(err)
	}

	// Dump fileHdr.
	if _, err := pw.Write([]byte{'P', 'E', 0, 0}); err != nil {
		return errutil.Err(err)
	}
	if err := binary.Write(pw, binary.LittleEndian, fileHdr); err != nil {
		return errutil.Err(err)
	}

	// Dump optional header.
	if err := binary.Write(pw, binary.LittleEndian, optHdr.OptHeader32); err != nil {
		return errutil.Err(err)
	}
	if err := binary.Write(pw, binary.LittleEndian, optHdr.DataDirs); err != nil {
		return errutil.Err(err)
	}

	// Dump section headers.
	for _, sectHdr := range sectHdrs {
		if err := binary.Write(pw, binary.LittleEndian, sectHdr); err != nil {
			return errutil.Err(err)
		}
	}

	return nil
}

// dumpIncBin stores include binary directives for the given files to the
// specified Assembly file.
func dumpIncBin(asmPath string, binPaths []string) error {
	t := template.New("incbin")
	const mainContent = `
BITS 32

{{range . -}}
incbin '{{.}}'
{{end}}`
	if _, err := t.Parse(mainContent[1:]); err != nil {
		return errutil.Err(err)
	}
	fw, err := os.Create(asmPath)
	if err != nil {
		return errutil.Err(err)
	}
	defer fw.Close()
	if err := t.Execute(fw, binPaths); err != nil {
		return errutil.Err(err)
	}
	return nil
}

// A PadWriter is an io.Writer which pads the output to the given alignment when
// closed.
type PadWriter struct {
	// Underlying io.Writer.
	w io.WriteCloser
	// Alignment, ensured at call to Close.
	align int
	// Bytes written.
	n int
}

// NewPadWriter returns an io.Writer for w which pads the output to the given
// alignment when closed.
func NewPadWriter(w io.WriteCloser, align int) *PadWriter {
	return &PadWriter{w: w, align: align}
}

func (pw *PadWriter) Write(p []byte) (n int, err error) {
	n, err = pw.w.Write(p)
	pw.n += n
	return n, err
}

// Close pads to the given alignment before closing the underlying io.Writer.
func (pw *PadWriter) Close() error {
	rem := pw.n % pw.align
	if rem != 0 {
		rem = pw.align - rem
	}
	pad := make([]byte, rem)
	if _, err := pw.w.Write(pad); err != nil {
		return errutil.Err(err)
	}
	return pw.w.Close()
}

// stringFromSZ converts a NULL-terminated string into a Go string.
func stringFromSZ(s []byte) string {
	for i, b := range s {
		if b == 0 {
			s = s[:i]
			break
		}
	}
	return string(s)
}
