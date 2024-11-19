CC = g++

SRC = ../src/
BIN = bin

CFLAGS = -Wall -g -std=c++17 -lncurses

TARGET = logger-test

SRCS = test.cpp \
       ../src/logger.cpp
OBJS = $(SRCS:$(SRC)/%.cpp=$(BIN)/%.o)

all: pre-build $(BIN)/$(TARGET)

pre-build:
	mkdir -p $(BIN)

$(BIN)/$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) $(NCURSES_FLAG)

$(BIN)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BIN)/*.o $(BIN)/$(TARGET)

.PHONY: all clean pre-build build
