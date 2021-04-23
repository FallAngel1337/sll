# $ gcc -Wall -Wextra -I. -o sll.o -c sll.c 
# $ gcc -g -Wall -o main -I. main.c sll.o
# $ ./main

# Compiler to be used
CC=gcc

# Compiler flags
CFLAGS=-g -Wall -Wextra

BIN=bin/main.out
SRCDIR=src

$(BIN): main.c src/sll.o
	@mkdir -p bin/
	$(CC) $(CFLAGS) -I$(SRCDIR)/ -o $@ $^

$(SRCDIR)/sll.o: $(SRCDIR)/sll.c $(SRCDIR)/sll.h
	$(CC) $(CFLAGS) -I$(SRCDIR)/ -o $@ -c $<
