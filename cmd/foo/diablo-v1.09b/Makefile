all: d.exe

d.exe: main.asm
	nasm -f bin -o $@ $<

main.asm: pe-hdr.bin _text.bin _rdata.bin _data.bin _rsrc.bin

_text.bin: _text.asm
	make -C _text
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
	rm -f _text/*.asm _text/*.bin
	rmdir --ignore-fail-on-non-empty _text
	rm -f _rdata/*.asm _rdata/*.bin
	@rmdir --ignore-fail-on-non-empty _rdata 2>/dev/null; true
	rm -f _data/*.asm _data/*.bin
	@rmdir --ignore-fail-on-non-empty _data 2>/dev/null; true
