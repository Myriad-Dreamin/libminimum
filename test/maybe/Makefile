

CXXFLAGS += -I../../include \
			-I../../test/include \

LDFLAGS += -lgtest -lpthread \
		   -L../Debug64 \

COMPILECXX ?= $(CXX) $(CXXFLAGS) $(LDFLAGS)

test: test-gen
	build/test-main

build-dir:
	mkdir -p build

test-gen: build-dir
	$(COMPILECXX) test-main.cc -o build/test-main -g -std=c++17 -fmax-errors=1

clean:
	rm build/* -r


.PHONY: test
