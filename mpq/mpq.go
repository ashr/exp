// Package mpq provides access to MPQ archives.
package mpq

import (
	"bytes"
	"encoding/binary"
	"fmt"
	"io"
	"io/ioutil"
	"math"
	"sort"
	"strings"

	"github.com/pkg/errors"
)

// An Archive is an MPQ archive.
type Archive struct {
	// MPQ header.
	header
	// Hash entries.
	hashes []hashEntry
	// Block entries.
	blocks []blockEntry
	// Underlying io.ReaderAt of the archive.
	r io.ReaderAt
	// Section size in bytes.
	sectorSize uint32
}

// Open opens the given MPQ archive.
func Open(mpqPath string) (*Archive, error) {
	// Open MPQ archive.
	buf, err := ioutil.ReadFile(mpqPath)
	if err != nil {
		return nil, errors.WithStack(err)
	}
	r := bytes.NewReader(buf)
	a := &Archive{
		r: r,
	}

	// Parse MPQ header.
	if err := binary.Read(r, binary.LittleEndian, &a.header); err != nil {
		return nil, errors.WithStack(err)
	}
	want := "MPQ\x1A"
	got := string(a.Magic[:])
	if got != want {
		return nil, errors.Errorf("magic header mismatch; expected %q, got %q", want, got)
	}

	// Decrypt hash table.
	const hashEntrySize = 16
	n := hashEntrySize * int64(a.HashCount)
	enc := make([]byte, n)
	if _, err := a.r.ReadAt(enc, int64(a.HashTableOffset)); err != nil {
		return nil, errors.WithStack(err)
	}
	dec := decrypt(enc, hashTableKey)

	// Parse hash table.
	a.hashes = make([]hashEntry, a.HashCount)
	if err := binary.Read(bytes.NewReader(dec), binary.LittleEndian, &a.hashes); err != nil {
		return nil, errors.WithStack(err)
	}

	// Decrypt block table.
	const blockEntrySize = 16
	n = blockEntrySize * int64(a.BlockCount)
	enc = make([]byte, n)
	if _, err := a.r.ReadAt(enc, int64(a.BlockTableOffset)); err != nil {
		return nil, errors.WithStack(err)
	}
	dec = decrypt(enc, blockTableKey)

	// Parse block table.
	a.blocks = make([]blockEntry, a.BlockCount)
	if err := binary.Read(bytes.NewReader(dec), binary.LittleEndian, &a.blocks); err != nil {
		return nil, errors.WithStack(err)
	}

	// Compute sector size.
	a.sectorSize = 512 * uint32(math.Pow(2, float64(a.SectorSizeExp)))

	return a, nil
}

// Files returns the list of file paths contained within the archive.
func (a *Archive) Files() []string {
	relPaths := make([]string, 0, len(a.hashes))
	for _, hash := range a.hashes {
		if hash.HashA == 0xFFFFFFFF && hash.HashB == 0xFFFFFFFF {
			// skip unused hash.
			continue
		}
		key := hashAB{hashA: hash.HashA, hashB: hash.HashB}
		relPath, ok := listings[key]
		if !ok {
			panic(fmt.Errorf("unable to locate path with hash A 0x%08X and hash B 0x%08X", key.hashA, key.hashB))
		}
		relPaths = append(relPaths, relPath)
	}
	sort.Strings(relPaths)
	return relPaths
}

// ReadFile returns the contents of the given file in the archive.
func (a *Archive) ReadFile(relPath string) ([]byte, error) {
	// Locate hash entry associated with the file.
	relPath = strings.Replace(relPath, "/", "\\", -1)
	hash, err := a.locateHash(relPath)
	if err != nil {
		return nil, errors.WithStack(err)
	}
	_ = hash

	panic("not yet implemented")
}

// locateHash locates the hash entry of the given file.
func (a *Archive) locateHash(relPath string) (hashEntry, error) {
	index := genHash(relPath, hashTableIndex)
	hashA := genHash(relPath, hashPathA)
	hashB := genHash(relPath, hashPathB)
	mask := a.HashCount - 1
	// startIndex specifies an index into the hash table, from where to start
	// searching for the hash entry of the given file.
	startIndex := index & mask
	for _, hash := range a.hashes[startIndex:] {
		if hash.HashA == hashA && hash.HashB == hashB {
			return hash, nil
		}
	}
	// The hash table wraps around. For instance, the diabdat.mpq hash table
	// contains 4096 entries, and the start index of "sfx/towners/healer25.wav"
	// is at 4089, while the actual hash entry index of healer25.wav is at 0.
	for _, hash := range a.hashes[:startIndex] {
		if hash.HashA == hashA && hash.HashB == hashB {
			return hash, nil
		}
	}
	return hashEntry{}, errors.Errorf("unable to locate hash entry for %q", relPath)
}

// A header is an MPQ header.
type header struct {
	// Magic signature; "MPQ\x1A"
	Magic [4]byte
	// Size in bytes of the MPQ header.
	HeaderSize uint32
	// Size in bytes of the MPQ archive.
	ArchiveSize uint32
	// MPQ format version.
	FormatVersion uint16
	// Sector size exponent.
	//
	//    sectorSize = 512 * 2^SectorSizeExp.
	SectorSizeExp uint16
	// Offset to the start of the hash table.
	HashTableOffset uint32
	// Offset to the start of the block table.
	BlockTableOffset uint32
	// Number of hash table entires.
	HashCount uint32
	// Number of block table entires.
	BlockCount uint32
}

// A hashEntry is a hash table entry.
type hashEntry struct {
	// Hash of relative file path, using method A.
	HashA uint32
	// Hash of relative file path, using method B.
	HashB uint32
	// Language locale of the file.
	Locale uint16
	// Platform of the file.
	Platform uint16
	// Index into the block table for the file; or one of the following two
	// values.
	//
	//    0xFFFFFFFF   empty hash table entry; terminate search for file.
	//    0xFFFFFFFE   empty hash table entry; continue search for file.
	BlockIndex uint32
}

// A blockEntry is a block table entry.
type blockEntry struct {
	// Offset to the start of the block.
	BlockOffset uint32
	// Size in bytes of the block.
	BlockSize uint32
	// Size in bytes of the uncompressed file.
	FileSize uint32
	// Flags associated with the block.
	Flags blockFlag
}

// blockFlag represents the set of block flags.
type blockFlag uint32

// Block flags.
const (
	fileImplode    blockFlag = 0x00000100 // compressed file (PKWARE)
	fileCompress   blockFlag = 0x00000200 // compressed file
	fileEncrypted  blockFlag = 0x00010000 // encrypted file
	filePosDepKey  blockFlag = 0x00020000 // position dependent decryption key
	filePatchFile  blockFlag = 0x00100000 // incremental patch file for an existing file in the base MPQ
	fileSingleUnit blockFlag = 0x01000000 // file contained in a single unit, not split in sections
	fileDeleted    blockFlag = 0x02000000 // deleted file; used by patch archives to delete files in lower-priority archives
	fileSectorCRC  blockFlag = 0x04000000 // sector CRC checksums
	fileExists     blockFlag = 0x80000000 // file present
)

// String returns the string representation of the block flags.
func (flags blockFlag) String() string {
	var ss []string
	masks := map[blockFlag]string{
		fileImplode:    "IMPLODE",
		fileCompress:   "COMPRESS",
		fileEncrypted:  "ENCRYPTED",
		filePosDepKey:  "POSITION_DEPENDENT_KEY",
		filePatchFile:  "PATCH_FILE",
		fileSingleUnit: "SINGLE_UNIT",
		fileDeleted:    "DELETED",
		fileSectorCRC:  "SECTOR_CRC",
		fileExists:     "EXISTS",
	}
	var keys []blockFlag
	for key := range masks {
		keys = append(keys, key)
	}
	less := func(i, j int) bool {
		return keys[i] < keys[j]
	}
	sort.Slice(keys, less)
	for _, mask := range keys {
		if flags&mask != 0 {
			ss = append(ss, masks[mask])
		}
	}
	if len(ss) == 0 {
		return "<no block flags>"
	}
	return strings.Join(ss, " | ")
}
