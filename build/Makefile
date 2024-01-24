# Compiler and flags 
CC = gcc
CFLAGS = -Wall -std=c99

# Build executable
build: src/main.c
	$(CC) $(CFLAGS) -o main main.c


# Clean Up 
clean: 
	rm -f build/main


.PHONY: build clean
