# Makefile pro projekt Block Editor
# 2018, FIT VUT
# Eliska Kadlecova, xkadle34
# Daniel Doubek, xdoube03
CC=g++
CFLAGS= -pthread -Wall -Wextra

TARGET=blockeditor
OBJECTS=main.o block.o scheme.o sumblock.o greatblock.o idivblock.o lessblock.o mulblock.o subblock.o

all: clean $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

run: all
	./blockeditor

doxygen:
			#TODO
clean:
	rm -f $(OBJECTS) $(TARGET)

pack: clean
	zip xkadle34-xdoube03.zip * ./doc/* ./examples/* ./src/* Makefile README.txt
