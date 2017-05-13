//+build ignore

package main

import (
	"fmt"
	"io/ioutil"
	"log"
)

func main() {
	listfile, err := ioutil.ReadFile("listfile.txt")
	if err != nil {
		log.Fatal(err)
	}
	const source = "// Code generated by \"go run gen.go\"; DO NOT EDIT.\n\npackage mpq\n\nvar listfile = `\n%s`\n"
	data := fmt.Sprintf(source, listfile)
	if err := ioutil.WriteFile("data.go", []byte(data), 0644); err != nil {
		log.Fatal(err)
	}
}