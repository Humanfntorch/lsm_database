CC=g++
CXXFLAGS=-std=c++17 -Wall -Werror -Wextra -pedantic

SRC_DIR=./src/Node/
TEST_DIR=./tests/

# Path to the Google Test libraries
GTEST_DIR = ./tests/
GTEST_LIBS = $(GTEST_DIR)libgtest_main.a $(GTEST_DIR)libgtest.a

# Define the source files for the classes needed for testing
NODE_SOURCES := $(wildcard $(SRC_DIR)*.cpp)
NODE_OBJECTS := $(NODE_SOURCES:.cpp=.o)

# Define the source files for the tests
TEST_SOURCES := $(wildcard $(TEST_DIR)*.cpp)
TEST_OBJECTS := $(TEST_SOURCES:.cpp=.o)

# Executable ot run all tests
BIN=test

all: $(BIN)

$(BIN): $(NODE_OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CXXFLAGS) -o $@ $^ $(GTEST_LIBS)

# Rule to compile Node source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

# Rule to compile test source files into object files
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(NODE_OBJECTS) $(TEST_OBJECTS) $(BIN)

.PHONY: all clean

