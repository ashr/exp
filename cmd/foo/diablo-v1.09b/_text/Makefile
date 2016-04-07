# *.asm -> *.bin
ASM = $(wildcard *.asm)
BIN = $(ASM:.asm=.bin)

all: $(BIN)

%.bin: %.asm
	nasm -f bin -o $@ $<

.PHONY: clean

clean:
	rm -rf *.bin
