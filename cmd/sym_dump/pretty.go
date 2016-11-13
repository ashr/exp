package main

import (
	"fmt"
	"log"
	"os"
	"path/filepath"
	"strings"
)

func pretty(fs map[string]*FuncDecl, globals map[string]*Global, types map[string]Type, fOrder, globalOrder, aliasOrder []string) {
	/*
	for _, name := range aliasOrder {
		typeName := alias[name]
		t := types[typeName]
		fmt.Println(t)
	}
	*/

	// Globals.
	for _, name := range globalOrder {
		global := globals[name]
		fmt.Printf("// Address: 0x%08X\n", global.Addr)
		fmt.Printf("%s;\n", global.Var)
	}

	return

	if err := os.MkdirAll("_dump_", 0755); err != nil {
		log.Fatal(err)
	}

	for _, name := range fOrder {
		f := fs[name]
		if len(f.Path) == 0 {
			fmt.Printf("// %s\n", f.Path)
			fmt.Println(f)
			fmt.Println()
			continue
		}
		path := strings.ToLower(f.Path)
		path = filepath.Clean(strings.Replace(path, "\\", "/", -1))
		path = path[len("c:/"):]
		dir, name := filepath.Split(path)
		dir = filepath.Join("_dump_", dir)
		if err := os.MkdirAll(dir, 0755); err != nil {
			log.Fatal(err)
		}
		path = filepath.Join(dir, name)
		file, err := os.OpenFile(path, os.O_RDWR|os.O_CREATE|os.O_APPEND, 0644)
		if err != nil {
			log.Fatal(err)
		}
		if _, err := file.WriteString(f.String() + "\n\n"); err != nil {
			log.Fatal(err)
		}
		if err := file.Close(); err != nil {
			log.Fatal(err)
		}
	}
}
