compiler := gcc
sdir := src
bdir := build
args := -I include

#only for developers if you want to install do make install
setup:
	mkdir $(bdir)

compile:
	$(compiler) $(args) $(sdir)/main.c -o $(bdir)/main

clean:
	rm $(bdir)/main.bin

install:
	mkdir $(bdir)
	$(compiler) $(args) $(sdir)/main.c -o $(bdir)/main
	sudo cp $(bdir)/main /bin/jhgconsole