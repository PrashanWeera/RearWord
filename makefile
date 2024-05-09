# A simple Makefile for compiling a C/C++ project

# Set the default goal (target) to be built when make is run without arguments
.DEFAULT_GOAL := all

# Define variables
SRC_DIR := src
OBJ_DIR := obj
TARGET_DIR := target
TARGET := $(TARGET_DIR)/ReadWord
INC_DIR = inc

# Define compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic -std=c99 -g

# Define source files by wildcard matching
SRCS := $(wildcard $(SRC_DIR)/*.c)

# Define object files by replacing .c with .o
OBJECTS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

# Define targets
all: $(TARGET)

# Build target executable
$(TARGET): $(OBJECTS) | $(TARGET_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INC_DIR)

# Create object and target directories
$(OBJ_DIR) $(TARGET_DIR):
	mkdir -p $@

# Run the target executable
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(TARGET_DIR)

# Ensure that 'clean' is not treated as a file name
.PHONY: all run clean