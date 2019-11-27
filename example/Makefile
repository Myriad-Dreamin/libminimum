
COMPILECXX ?= $(CXX) $(CXXFLAGS) $(LDFLAGS)
OUT_TO_BUILD ?= -I../include -o build/example -fmax-errors=1
PRINTGEN := print.cc $(OUT_TO_BUILD)
GRAPHGEN := graph.cc $(OUT_TO_BUILD)

print-hello-world: print-gen-hello-world
	build/example

build-dir:
	mkdir -p build

print-gen: build-dir
	$(COMPILECXX) -DHelloWorld -DBoolean -DPair -DSerialContainer -DQueueLikeContainer -DCombiningContainer $(PRINTGEN)

print-gen-hello-world: build-dir
	$(COMPILECXX) -DHelloWorld $(PRINTGEN)

print-gen-combining-container: build-dir
	$(COMPILECXX) -DCombiningContainer $(PRINTGEN)

print-gen-boolean: build-dir
	$(COMPILECXX) -DBoolean $(PRINTGEN)

print-gen-pair: build-dir
	$(COMPILECXX) -DPair $(PRINTGEN)

print-gen-serial-container: build-dir
	$(COMPILECXX) -DSerialContainer $(PRINTGEN)

print-gen-queue-like-container: build-dir
	$(COMPILECXX) -DQueueLikeContainer $(PRINTGEN)

graph-gen: build-dir
	$(COMPILECXX) $(GRAPHGEN)

print: print-gen
	build/example

print-combining-container: print-gen-combining-container
	build/example

print-boolean: print-gen-boolean
	build/example

print-pair: print-gen-pair
	build/example

print-serial-container: print-gen-serial-container
	build/example

print-queue-like-container: print-gen-queue-like-container
	build/example

graph: graph-gen
	build/example


clean:
	rm build/* -r
