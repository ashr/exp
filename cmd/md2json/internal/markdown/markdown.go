// Package markdown implements a blackfriday.Renderer which produces abstract
// syntax trees for Markdown.
//
// NOTE: The current implementation has not been well tested and should
// definitely not be used for anything serious beyond this proof of concept.
// Consider yourself warned :)
package markdown

import (
	"bytes"

	"github.com/russross/blackfriday"
)

// Parse parses the given Markdown document and returns its top-level
// declarations.
func Parse(input []byte, extensions int) []interface{} {
	renderer := &renderer{}
	blackfriday.Markdown(input, renderer, extensions)
	return renderer.nodes
}

// Ensure that the AST renderer implements the blackfriday.Renderer interface.
var _ blackfriday.Renderer = &renderer{}

// renderer implements the blackfriday.Renderer interface to produce abstract
// syntax trees for Markdown.
type renderer struct {
	// Top-level declarations of the Markdown document.
	nodes []interface{}
	// Node stack for child nodes of parent nodes.
	stack []interface{}
	// Number of parent nodes expecting child nodes.
	queue int
}

func (r *renderer) BlockCode(out *bytes.Buffer, text []byte, lang string) {
	node := BlockCode{
		Text: string(text),
		Lang: lang,
	}
	r.append(node)
}

func (r *renderer) BlockQuote(out *bytes.Buffer, text []byte) {
	node := BlockQuote{
		Text: string(text),
	}
	r.append(node)
}

func (r *renderer) BlockHtml(out *bytes.Buffer, text []byte) {
	node := BlockHtml{
		Text: string(text),
	}
	r.append(node)
}

func (r *renderer) Header(out *bytes.Buffer, text func() bool, level int, id string) {
	node := Header{
		Text:  r.child(text),
		Level: level,
		Id:    id,
	}
	r.append(node)
}

func (r *renderer) HRule(out *bytes.Buffer) {
	node := HRule{}
	r.append(node)
}

func (r *renderer) List(out *bytes.Buffer, text func() bool, flags int) {
	node := List{
		Text:  r.child(text),
		Flags: flags,
	}
	r.append(node)
}

func (r *renderer) ListItem(out *bytes.Buffer, text []byte, flags int) {
	node := ListItem{
		Text:  string(text),
		Flags: flags,
	}
	r.append(node)
}

func (r *renderer) Paragraph(out *bytes.Buffer, text func() bool) {
	node := Paragraph{
		Text: r.child(text),
	}
	r.append(node)
}

func (r *renderer) Table(out *bytes.Buffer, header []byte, body []byte, columnData []int) {
	node := Table{
		Header:     string(header),
		Body:       string(body),
		ColumnData: columnData,
	}
	r.append(node)
}

func (r *renderer) TableRow(out *bytes.Buffer, text []byte) {
	node := TableRow{
		Text: string(text),
	}
	r.append(node)
}

func (r *renderer) TableHeaderCell(out *bytes.Buffer, text []byte, flags int) {
	node := TableHeaderCell{
		Text:  string(text),
		Flags: flags,
	}
	r.append(node)
}

func (r *renderer) TableCell(out *bytes.Buffer, text []byte, flags int) {
	node := TableCell{
		Text:  string(text),
		Flags: flags,
	}
	r.append(node)
}

func (r *renderer) Footnotes(out *bytes.Buffer, text func() bool) {
	node := Footnotes{
		Text: r.child(text),
	}
	r.append(node)
}

func (r *renderer) FootnoteItem(out *bytes.Buffer, name, text []byte, flags int) {
	node := FootnoteItem{
		Name:  string(name),
		Text:  string(text),
		Flags: flags,
	}
	r.append(node)
}

func (r *renderer) TitleBlock(out *bytes.Buffer, text []byte) {
	node := TitleBlock{
		Text: string(text),
	}
	r.append(node)
}

func (r *renderer) AutoLink(out *bytes.Buffer, link []byte, kind int) {
	node := AutoLink{
		Link: string(link),
		Kind: kind,
	}
	r.append(node)
}

func (r *renderer) CodeSpan(out *bytes.Buffer, text []byte) {
	node := CodeSpan{
		Text: string(text),
	}
	r.append(node)
}

func (r *renderer) DoubleEmphasis(out *bytes.Buffer, text []byte) {
	node := DoubleEmphasis{
		Text: string(text),
	}
	r.append(node)
}

func (r *renderer) Emphasis(out *bytes.Buffer, text []byte) {
	node := Emphasis{
		Text: string(text),
	}
	r.append(node)
}

func (r *renderer) Image(out *bytes.Buffer, link []byte, title []byte, alt []byte) {
	node := Image{
		Link:  string(link),
		Title: string(title),
		Alt:   string(alt),
	}
	r.append(node)
}

func (r *renderer) LineBreak(out *bytes.Buffer) {
	node := LineBreak{}
	r.append(node)
}

func (r *renderer) Link(out *bytes.Buffer, link []byte, title []byte, content []byte) {
	node := Link{
		Link:    string(link),
		Title:   string(title),
		Content: string(content),
	}
	r.append(node)
}

func (r *renderer) RawHtmlTag(out *bytes.Buffer, tag []byte) {
	node := RawHtmlTag{
		Tag: string(tag),
	}
	r.append(node)
}

func (r *renderer) TripleEmphasis(out *bytes.Buffer, text []byte) {
	node := TripleEmphasis{
		Text: string(text),
	}
	r.append(node)
}

func (r *renderer) StrikeThrough(out *bytes.Buffer, text []byte) {
	node := StrikeThrough{
		Text: string(text),
	}
	r.append(node)
}

func (r *renderer) FootnoteRef(out *bytes.Buffer, ref []byte, id int) {
	node := FootnoteRef{
		Ref: string(ref),
		Id:  id,
	}
	r.append(node)
}

func (r *renderer) Entity(out *bytes.Buffer, entity []byte) {
	node := Entity{
		Entity: string(entity),
	}
	r.append(node)
}

func (r *renderer) NormalText(out *bytes.Buffer, text []byte) {
	node := NormalText{
		Text: string(text),
	}
	r.append(node)
}

func (r *renderer) DocumentHeader(out *bytes.Buffer) {
	node := DocumentHeader{}
	r.append(node)
}

func (r *renderer) DocumentFooter(out *bytes.Buffer) {
	node := DocumentFooter{}
	r.append(node)
}

func (r *renderer) GetFlags() int {
	return 0
}

// push pushes a node to the stack for later use by its parent node.
func (r *renderer) push(node interface{}) {
	r.stack = append(r.stack, node)
}

// pop pops the most recently added node from the stack.
func (r *renderer) pop() interface{} {
	if len(r.stack) == 0 {
		panic("invalid call to pop; stack is empty")
	}
	node := r.stack[len(r.stack)-1]
	r.stack = r.stack[:len(r.stack)-1]
	return node
}

// append the given node to the AST or to the child node stack if so expected by
// a parent node.
func (r *renderer) append(node interface{}) {
	if r.queue > 0 {
		r.push(node)
	} else {
		r.nodes = append(r.nodes, node)
	}
}

// child returns the child node of a parent node if such a node exists.
func (r *renderer) child(text func() bool) interface{} {
	r.queue++
	hasChild := text()
	r.queue--
	if hasChild {
		// empty the stack and merge subsequent NormalText nodes.
		children := r.stack
		child := merge(children)
		r.stack = r.stack[:0]
		return child
	}
	return nil
}

// NOTE: This function may be considered a hack which only handles special
// cases. However, it adds value by merging subsequent NormalText nodes
// containing underscores; e.g.
//
//    "towners", "_init", "_anim"
//    "towners_init_anim"

// merge merges subsequent NormalText nodes into single nodes and leaves other
// nodes intact.
func merge(children []interface{}) interface{} {
	nodes := Nodes{}
	for i := 0; i < len(children); i++ {
		node := children[i]
		if n0, ok := node.(NormalText); ok {
			var j int
			for j = i + 1; j < len(children); j++ {
				if n1, ok := children[j].(NormalText); ok {
					n0.Text += n1.Text
				} else {
					j--
					break
				}
			}
			i = j
			node = n0
		}
		nodes.Nodes = append(nodes.Nodes, node)
	}
	switch len(nodes.Nodes) {
	case 0:
		return nil
	case 1:
		return nodes.Nodes[0]
	default:
		return nodes
	}
}
