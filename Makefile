CC=clang
CFLAGS=-Iincludes/ -g -Wall -O3
SRC=./src
BIN=./bin

clean:
	rm -rf $(BIN)/*

ls:
	$(CC) $(SRC)/ls/main.c -o $(BIN)/ls $(CFLAGS)

touch: 
	$(CC) $(SRC)/touch/main.c -o $(BIN)/touch $(CFLAGS)
