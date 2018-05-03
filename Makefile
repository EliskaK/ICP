# Makefile pro projekt Block Editor
# 2018, FIT VUT
# Eliska Kadlecova, xkadle34
# Daniel Doubek, xdoube03
CC=g++
CFLAGS= -pthread -Wall -Wextra

TARGET=blockeditor
OBJECTS=wire.o qscheme.o qblockeditor.o port.o main.o block.o

all: clean 
	cd src && make  && mv blockeditor ../blockeditor

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

run: all
	./blockeditor

doxygen:
	cd src/ && doxygen Doxyfile && cp -r ./html ../doc && rm -rf ./html
clean:
	rm -f $(OBJECTS) $(TARGET)
	cd src && make clean

pack: clean
	zip xkadle34-xdoube03.zip * ./doc/* ./examples/* ./src/* Makefile README.txt
