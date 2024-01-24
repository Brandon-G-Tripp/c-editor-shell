# Compiler and flags 
CC = gcc
CFLAGS = -Wall -std=c99

# Build executable
main: src/main.c
	$(CC) $(CFLAGS) -o main src/main.c

# copy executable to top level 
install: main
	cp main .


# Clean Up 
clean: 
	rm -f main


# Phony targets 
.PHONY: main install clean

# Default rule 
all: install
