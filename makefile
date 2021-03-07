CC=g++
LIB=-lncurses

SRC_DIR=src
OBJ_DIR=obj

_OBJ=main.o
OBJ=$(patsubst %, $(OBJ_DIR)/%, $(_OBJ))

$(OBJ): main.cpp
	$(CC) -o $(OBJ) -c main.cpp

.PHONY: all run clean

all: $(OBJ)
	$(CC) -o all $(OBJ) $(LIB)

run: all
	./all

clean:
	rm $(OBJ_DIR)/*.o
