all: foo

foo:
	go install

run: foo
	foo diablo-v1.09b.exe

test: clean run
	make -s test -C diablo-v1.09b/

clean:
	make -s clean -C diablo-v1.09b/

.PHONY: clean run test
