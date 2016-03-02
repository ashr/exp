package markdown

type BlockCode struct {
	Text string
	Lang string
}

type BlockQuote struct {
	Text string
}

type BlockHtml struct {
	Text string
}

type Header struct {
	Text  interface{}
	Level int
	Id    string
}

type HRule struct {
}

type List struct {
	Text  interface{}
	Flags int
}

type ListItem struct {
	Text  string
	Flags int
}

type Paragraph struct {
	Text interface{}
}

type Table struct {
	Header     string
	Body       string
	ColumnData []int
}

type TableRow struct {
	Text string
}

type TableHeaderCell struct {
	Text  string
	Flags int
}

type TableCell struct {
	Text  string
	Flags int
}

type Footnotes struct {
	Text interface{}
}

type FootnoteItem struct {
	Name  string
	Text  string
	Flags int
}

type TitleBlock struct {
	Text string
}

type AutoLink struct {
	Link string
	Kind int
}

type CodeSpan struct {
	Text string
}

type DoubleEmphasis struct {
	Text string
}

type Emphasis struct {
	Text string
}

type Image struct {
	Link  string
	Title string
	Alt   string
}

type LineBreak struct {
}

type Link struct {
	Link    string
	Title   string
	Content string
}

type RawHtmlTag struct {
	Tag string
}

type TripleEmphasis struct {
	Text string
}

type StrikeThrough struct {
	Text string
}

type FootnoteRef struct {
	Ref string
	Id  int
}

type Entity struct {
	Entity string
}

type NormalText struct {
	Text string
}

type DocumentHeader struct {
}

type DocumentFooter struct {
}

// TODO: Figure out a better way to handle multiple child nodes than using the
// Nodes type.

type Nodes struct {
	Nodes []interface{}
}
