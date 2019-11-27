
build-dir:
	mkdir -p build

test-gen: build-dir
	g++ test-main.cc -lgtest -lpthread -o build/test-main -fmax-errors=1

test: test-gen
	build/test-main


.PHONY: test
