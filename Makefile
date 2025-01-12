compiler := gcc
sdir := src
bdir := build
args := -I include

setup:
	mkdir $(bdir)

compile:
	$(compiler) $(args) $(sdir)/main.c -o $(bdir)/main

clean:
	rm $(bdir)/main.bin

install:
	mkdir $(bdir)
	$(compiler) $(args) $(sdir)/main.c -o $(bdir)/jhgconsole
	sudo cp $(bdir)/jhgconsole /bin/jhgconsole
	rm -r $(bdir)