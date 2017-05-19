// The d1_dump tool retrieves information related to the Diablo 1 game (*.exe ->
// *.json).
package main

import (
	"flag"
	"fmt"
	"log"
	"os"

	"github.com/kr/pretty"
	"github.com/pkg/errors"
	"github.com/sanctuary/exp/d1"
)

func usage() {
	const use = `
Retrieve information related to the Diablo 1 game (*.exe -> *.json).

Usage:

	d1_dump [OPTION]... diablo.exe

Flags:
`
	fmt.Fprint(os.Stderr, use[1:])
	flag.PrintDefaults()
}

func main() {
	// Parse command line arguments.
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		flag.Usage()
		os.Exit(1)
	}
	exePath := flag.Arg(0)

	// Dump information from diablo.exe.
	if err := dump(exePath); err != nil {
		log.Fatalf("%+v", err)
	}
}

// dump retrieves information stored within the diablo.exe executable.
func dump(exePath string) error {
	exe, err := d1.ParseFile(exePath)
	if err != nil {
		return errors.WithStack(err)
	}
	pretty.Println("monsters:", exe.Monsters)
	return nil
}
