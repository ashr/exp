// md2json is a tool for converting notes from Markdown to JSON format.
//
//    Usage: md2json FILE...
//
// NOTE: This is a very rought proof of concept. It will panic for many trivial
// Markdown files with a slightly different structure than the one expected. At
// this stage, it is meant to evaluate of it is worth doing the Markdown to JSON
// conversion in the first place.
package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"os"

	"github.com/mewkiz/pkg/errutil"
	"github.com/russross/blackfriday"
	"github.com/sanctuary/exp/cmd/md2json/internal/markdown"
)

func usage() {
	fmt.Fprintln(os.Stderr, "Usage: md2json FILE...")
	flag.PrintDefaults()
}

func main() {
	flag.Usage = usage
	flag.Parse()
	for _, path := range flag.Args() {
		if err := md2json(path); err != nil {
			log.Fatal(err)
		}
	}
}

// md2json renders the given Markdown file as JSON.
func md2json(path string) error {
	input, err := ioutil.ReadFile(path)
	if err != nil {
		return errutil.Err(err)
	}
	extensions := 0 |
		blackfriday.EXTENSION_NO_INTRA_EMPHASIS |
		blackfriday.EXTENSION_TABLES |
		blackfriday.EXTENSION_FENCED_CODE |
		blackfriday.EXTENSION_AUTOLINK |
		blackfriday.EXTENSION_SPACE_HEADERS |
		blackfriday.EXTENSION_NO_EMPTY_LINE_BEFORE_BLOCK
	nodes := markdown.Parse(input, extensions)
	addrmap := genAddrMapping(nodes)
	buf, err := json.MarshalIndent(addrmap, "", "\t")
	if err != nil {
		return errutil.Err(err)
	}
	fmt.Println(string(buf))
	return nil
}

// genAddrMapping generates a mapping from addresses to declarations.
func genAddrMapping(nodes []interface{}) map[string]string {
	var curAddr string
	addrmap := make(map[string]string)
	for _, node := range nodes {
		switch n := node.(type) {
		case markdown.Header:
			// ## 0x46019B
			if n.Level == 2 {
				curAddr = getString(n.Text)
			}
		case markdown.BlockCode:
			if curAddr == "" {
				panic("code block before first ## address header")
			}
			addrmap[curAddr] = n.Text
		}
	}
	return addrmap
}

// getString returns the text string of the given node.
func getString(node interface{}) string {
	if n, ok := node.(markdown.NormalText); ok {
		return n.Text
	}
	panic(fmt.Sprintf("getString: support for %T nodes not yet implemented", node))
}
