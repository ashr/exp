package main

import (
	"bytes"
	"encoding/json"
	"log"
	"os/exec"
	"path/filepath"
	"sort"
	"strconv"
	"strings"

	"github.com/mewkiz/pkg/errutil"
	"github.com/mewkiz/pkg/goutil"
)

var (
	// notesDir specifies the absolute path to the notes repository.
	notesDir string
	// textDecls map from file name to declarations of the ".text" section.
	textDecls map[string][]Decl
	// rdataDecls map from file name to declarations of the ".rdata" section.
	rdataDecls map[string][]Decl
	// dataDecls map from file name to declarations of the ".data" section.
	dataDecls map[string][]Decl
	// bssDecls map from file name to declarations of the ".bss" section.
	bssDecls map[string][]Decl
)

// TODO: use struct { addr uint64; decl string } instead of map.

// A Decl specifies the declaration of a given address.
type Decl struct {
	// Address.
	Addr uint64
	// Declaration with doc comment.
	Decl string
}

// initNotesDir locates the notes source directory.
func initNotesDir() error {
	var err error
	notesDir, err = goutil.SrcDir("github.com/sanctuary/notes")
	if err != nil {
		return errutil.Err(err)
	}
	return nil
}

// parseFileDecls parses the Markdown declaration files for each source file of
// the ".text", ".rdata", ".data" and ".bss" segments.
func parseFileDecls(sectName string, files []*SourceFile) error {
	// Parse declarations.
	for _, file := range files {
		switch {
		case strings.HasPrefix(file.Name, "_crt"), strings.HasPrefix(file.Name, "pkware"), strings.HasPrefix(file.Name, "_idata"):
			// Skip.
			continue
		}
		name := file.Name + ".md"
		path := filepath.Join(notesDir, "functions", name)
		decls, err := parseDecls(path)
		if err != nil {
			return errutil.Newf("unable to parse declarations for section %q: %v", sectName, err)
		}
		file.Decls = decls
	}
	return nil
}

// parseDecls parses the given Markdown file of the notes repo and returns a
// slice of the declarations declared within.
func parseDecls(path string) ([]Decl, error) {
	buf := new(bytes.Buffer)
	cmd := exec.Command("md2json", "-empty", path)
	cmd.Stdout = buf
	if verbose {
		log.Printf("cmd: `%v`\n", strings.Join(cmd.Args, " "))
	}
	if err := cmd.Run(); err != nil {
		return nil, errutil.Newf("unable to execute command %q; %v", cmd.Args, err)
	}
	var m map[string]string
	dec := json.NewDecoder(bytes.NewReader(buf.Bytes()))
	if err := dec.Decode(&m); err != nil {
		return nil, errutil.Err(err)
	}
	var decls Decls
	for rawAddr, decl := range m {
		if strings.HasPrefix(rawAddr, "0x") {
			rawAddr = rawAddr[2:]
		}
		addr, err := strconv.ParseUint(rawAddr, 16, 32)
		if err != nil {
			return nil, errutil.Err(err)
		}
		decls = append(decls, Decl{Addr: addr, Decl: decl})
	}
	sort.Sort(decls)
	return decls, nil
}

type Decls []Decl

func (d Decls) Less(i, j int) bool {
	return d[i].Addr < d[j].Addr
}

func (d Decls) Len() int {
	return len(d)
}

func (d Decls) Swap(i, j int) {
	d[i], d[j] = d[j], d[i]
}
