all: d.exe

d.exe: main.asm
	nasm -f bin -o $@ $<

main.asm: pe-hdr.bin _text.bin _rdata.bin _data.bin _rsrc.bin

_text.bin: _text.asm
	nasm -f bin -o $@ $<

_rdata.bin: _rdata.asm
	nasm -f bin -o $@ $<

_data.bin: _data.asm
	nasm -f bin -o $@ $<

.PHONY: clean test

test: d.exe
	sha1sum -c d.sha1

clean:
	rm -f d.exe main.asm _text.asm _rdata.asm _data.asm pe-hdr.bin _text.bin _rdata.bin _data.bin _rsrc.bin
	rm -rf _text _rdata _data
