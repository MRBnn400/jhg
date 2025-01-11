compiler := gcc
sdir := src
bdir := build
args := -I include

compile:
	$(compiler) $(args) $(sdir)/main.c -o $(bdir)/main

clean:
	rm $(bdir)/main.bin

install:
	$(compiler) $(args) $(sdir)/main.c -o $(bdir)/jhgconsole
	sudo cp $(bdir)/jhgconsole /bin/jhgconsole