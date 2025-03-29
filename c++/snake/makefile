CFLAGS=-I include -Wall
LDFLAGS=-lncurses
OBJS=$(patsubst src/%.cpp, $(BUILD_DIR)/%.o, $(wildcard src/*.cpp) main.cpp)
BUILD_DIR=build
BIN_DIR=bin

.DEFAULT_GOAL := all

$(BUILD_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: src/%.cpp main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: clean compile start

compile: $(BUILD_DIR) $(BIN_DIR) $(OBJS)
	$(CC) -o $(BIN_DIR)/app $(OBJS) $(LDFLAGS)

start: $(BIN_DIR)/app
	$(BIN_DIR)/app

clean:
	rm -f $(BUILD_DIR)/*.o $(BIN_DIR)/app
