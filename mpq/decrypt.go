//go:generate go run gen.go

package mpq

import (
	"bufio"
	"encoding/binary"
	"fmt"
	"log"
	"path"
	"sort"
	"strings"

	"github.com/pkg/errors"
)

var (
	// Lookup table used during decryption.
	cryptTable [0x500]uint32
	// Key used to decrypt the hash table.
	hashTableKey uint32
	// Key used to decrypt the block table.
	blockTableKey uint32
)

func init() {
	// Initialize crypt table.
	initCryptTable()

	// initialize hash table key and block table key.
	hashTableKey = genFileKey("(hash table)")
	blockTableKey = genFileKey("(block table)")

	// Initialize file listings.
	if err := initListings(); err != nil {
		log.Fatalf("%+v", err)
	}
}

// initCryptTable initializes the lookup table used during decryption.
func initCryptTable() {
	//start := time.Now()
	seed := uint32(0x00100001)
	for index1 := 0; index1 < 0x100; index1++ {
		index2 := index1
		for i := 0; i < 5; i++ {
			seed = (seed*125 + 3) % 0x2AAAAB
			temp1 := (seed & 0xFFFF) << 0x10
			seed = (seed*125 + 3) % 0x2AAAAB
			temp2 := (seed & 0xFFFF)
			cryptTable[index2] = (temp1 | temp2)
			index2 += 0x100
		}
	}
	// Takes on average 60.00 µs.
	//fmt.Println("init of crypt tables took:", time.Since(start))
}

// decrypt decrypts the source data in-place with the given key.
func decrypt(src []byte, key uint32) []byte {
	// Preprocess; convert []byte to []uint32.
	xs := make([]uint32, len(src)/4)
	for i := range xs {
		xs[i] = binary.LittleEndian.Uint32(src[i*4:])
	}

	seed := uint32(0xEEEEEEEE)
	for i := range xs {
		seed += cryptTable[0x400+(key&0xFF)]
		xs[i] ^= key + seed
		key = ((^key << 0x15) + 0x11111111) | (key >> 0x0B)
		seed = xs[i] + seed + (seed << 5) + 3
	}

	// Preprocess; convert []uint32 to []byte.
	for i, x := range xs {
		binary.LittleEndian.PutUint32(src[i*4:], x)
	}
	return src
}

// hashType represents the set of hash types.
type hashType uint32

// Hash types.
const (
	// Hash of relative file path, which specifies an index hash the hash table,
	// from where to start searching for the hash entry associated with the given
	// file.
	hashTableIndex hashType = 0x000
	// Hash of relative file path, using method A.
	hashPathA hashType = 0x100
	// Hash of relative file path, using method B.
	hashPathB hashType = 0x200
	// Hash of the file name, which specifies the encryption key of the file.
	hashFileKey hashType = 0x300
)

// genHash returns the hash of the given string, based on the specified hash
// type.
func genHash(s string, hashType hashType) uint32 {
	s = strings.ToUpper(s)
	seed1 := uint32(0x7FED7FED)
	seed2 := uint32(0xEEEEEEEE)
	for i := 0; i < len(s); i++ {
		v := uint32(s[i])
		seed1 = cryptTable[uint32(hashType)+v] ^ (seed1 + seed2)
		seed2 = v + seed1 + seed2 + (seed2 << 5) + 3
	}
	return seed1
}

// genFileKey returns the encryption key of the given file.
func genFileKey(relPath string) uint32 {
	relPath = strings.Replace(relPath, "\\", "/", -1)
	name := path.Base(relPath)
	return genHash(name, hashFileKey)
}

// listings maps file hashes to their original file paths.
var listings map[hashAB]string

// hashAB contains both the A and B hashes of a given file, to be used as key
// for file listings.
type hashAB struct {
	// Hash of relative file path; using method A.
	hashA uint32
	// Hash of relative file path; using method B.
	hashB uint32
}

// initListings initializes the file listings.
func initListings() error {
	//start := time.Now()
	s := bufio.NewScanner(strings.NewReader(listfile))
	var paths []string
	for s.Scan() {
		path := s.Text()
		paths = append(paths, path)
	}
	if err := s.Err(); err != nil {
		return errors.WithStack(err)
	}
	sort.Strings(paths)
	listings = make(map[hashAB]string)
	for _, path := range paths {
		hashA := genHash(path, hashPathA)
		hashB := genHash(path, hashPathB)
		key := hashAB{hashA: hashA, hashB: hashB}
		if prev, ok := listings[key]; ok {
			panic(fmt.Errorf("hash collision between %q and %q", prev, path))
		}
		listings[key] = path
	}
	// Takes on average 20.00 ms.
	//fmt.Println("init of listings took:", time.Since(start))
	return nil
}
