compiler := gcc
sdir := src
bdir := build
args := -I include

compile:
	$(compiler) $(args) $(sdir)/main.c -o $(bdir)/main.bin

clean:
	rm $(bdir)/main.bin