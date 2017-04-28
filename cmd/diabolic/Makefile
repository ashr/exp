all: diablo-v1.09b_69.ll

gen: diablo-v1.09b_69.lst
	# funcs.json blocks.json data.json tables.json sigs.json
	lst2json $<

sigs.h: sigs.json
	sigs2h -o $@ $<
	hfix -o $@ $@

sigs.ll: sigs.h
	h2ll -o $@ $<

imports.h: imports.json
	sigs2h -o $@ $<
	hfix -pre -partial -o $@ $@

imports.ll: imports.h
	h2ll -sigs imports.json -o $@ $<

diablo-v1.09b_69.ll: diablo-v1.09b.exe funcs.json blocks.json data.json tables.json sigs.ll
	bin2ll -func 0x417518 $<
