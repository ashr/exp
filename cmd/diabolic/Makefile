all: diablo-v1.09b_69.ll

gen: funcs.json blocks.json data.json tables.json

%.json: diablo-v1.09b_69.lst
	lst2json $<

diablo-v1.09b_69.ll: diablo-v1.09b.exe funcs.json blocks.json data.json tables.json
	bin2ll -func 0x417518 $<
