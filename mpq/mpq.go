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
	// Sector size in bytes.
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
	fmt.Println("a.HashCount:", a.HashCount)
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
	// Locate hash and block entry associated with the file.
	relPath = strings.Replace(relPath, "/", "\\", -1)
	hash, err := a.locateHash(relPath)
	if err != nil {
		return nil, errors.WithStack(err)
	}
	block := a.blocks[hash.BlockIndex]

	// Compute file encryption key.
	fileKey := genFileKey(relPath)

	// Calculate number of sectors.
	nsectors := int(block.FileSize / a.sectorSize)
	// even specifies whether the file size is an even multiple of sector size.
	even := block.FileSize%a.sectorSize == 0
	if !even {
		nsectors++
	}

	// Decode sector offset table.
	sectorOffsets, err := a.decodeSectorOffsets(fileKey, block, nsectors, even)
	if err != nil {
		return nil, errors.WithStack(err)
	}

	// NOTE: Extraction works for diabdat.mpq but is broken for the drtl109b.exe
	// overlay MPQ, which contains the diablo-109b.exe binary patch.

	// TODO: Clean up the code from this point until the end of the function.
	// Extract file data by optionally decrypting and exploding the content of
	// its sectors.
	data := make([]byte, 0, block.FileSize)
	for i, start := range sectorOffsets[:len(sectorOffsets)-1] {
		end := sectorOffsets[i+1]
		size := end - start
		enc := make([]byte, size)
		if _, err := a.r.ReadAt(enc, int64(block.BlockOffset+start)); err != nil {
			return nil, errors.WithStack(err)
		}
		var dec []byte
		if block.Flags&fileEncrypted != 0 {
			// Compute sector encryption key based on file key.
			sectorKey := fileKey + uint32(i)
			// Decrypt sector content.
			dec = decrypt(enc, sectorKey)
		} else {
			// The sector content is not encrypted.
			dec = enc
		}

		isZipped := block.Flags&fileImplode != 0
		if i == nsectors-1 && uint32(len(data)+len(dec)) == block.FileSize {
			// Copy the last sector raw if the file size is equal to the
			// (nsectors-1)*sectorSize + size of last decrypted sector.
			isZipped = false
		}
		if uint32(len(dec)) == a.sectorSize {
			// Copy the sector raw if the decrypted sector content length is equal
			// to the sector size.
			isZipped = false
		}
		if isZipped {
			// Explode sector with PKZIP.
			sector, err := explode(dec)
			if err != nil {
				return nil, errors.WithStack(err)
			}
			// Trim trailing zeroes from the sector, which are present if the file
			// size is not an even multiple of sector size, and the last sector was
			// compressed.
			//
			// The last sector would otherwise add sectorSize bytes to data, rather
			// than block.FileSize%sectorSize bytes.
			if i == nsectors-1 && !even {
				sector = sector[:block.FileSize%a.sectorSize]
			}
			data = append(data, sector...)
		} else {
			// The section content is not compressed.
			data = append(data, dec...)
		}
	}

	// Sanity check of file length.
	if uint32(len(data)) != block.FileSize {
		return nil, errors.Errorf("file content length mismatch; expected %d, got %d", block.FileSize, len(data))
	}
	return data, nil
}

// decodeSectorOffsets decodes and returns the sector offset table of the given
// file.
func (a *Archive) decodeSectorOffsets(fileKey uint32, block blockEntry, nsectors int, even bool) ([]uint32, error) {
	// Compressed file.
	sectorOffsets := make([]uint32, (nsectors + 1))
	if block.Flags&fileImplode != 0 {
		// Decrypt sector offset table.
		sectorOffsetTableKey := fileKey - 1
		const int32Size = 4
		enc := make([]byte, (nsectors+1)*int32Size)
		if _, err := a.r.ReadAt(enc, int64(block.BlockOffset)); err != nil {
			return nil, errors.WithStack(err)
		}
		dec := decrypt(enc, sectorOffsetTableKey)
		if err := binary.Read(bytes.NewReader(dec), binary.LittleEndian, &sectorOffsets); err != nil {
			return nil, errors.WithStack(err)
		}
		return sectorOffsets, nil
	}
	offset := uint32(0)
	// Uncompressed file.
	for i := range sectorOffsets {
		sectorOffsets[i] = offset
		// The size of each sector within an uncompressed block is implicitly
		// sectorSize number of bytes.
		//
		// If the file size is not an even multiple of sectorSize, the size of the
		// last sector is fileSize%sectorSize.
		if i == nsectors-1 && !even {
			offset += block.FileSize % a.sectorSize
		} else {
			offset += a.sectorSize
		}
	}
	return sectorOffsets, nil
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
	fileSingleUnit blockFlag = 0x01000000 // file contained in a single unit, not split in sectors
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
