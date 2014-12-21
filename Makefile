CC=clang
CFLAGS=-Iincludes/ -g -Wall -O3
SRC=./src
BIN=./bin

ls:
	$(CC) $(SRC)/ls/main.c -o $(BIN)/ls $(CFLAGS)

clean:
	rm -rf $(BIN)/*
