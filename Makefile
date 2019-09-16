TARGET=main

# all .c files in this directory are my sources
SOURCES=$(wildcard *.cpp)

OBJS=$(SOURCES:.cpp=.o)

INC_DIR=../include
CC=g++
CFLAGS= -c -pedantic -Wall -Werror -Wconversion -ansi -g -I$(INC_DIR)
CXXFLAGS=$(CFLAGS)
LDFLAGS= -g

.PHONY: clean run gdb

$(TARGET): $(OBJS)

include .depends

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

# Do not forget to add '-g' to CFLAGS
gdb: $(TARGET)
	gdb -q ./$(TARGET)

