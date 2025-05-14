# compiler and flags
CC := g++
CFLAGS := -Wall -Wextra -std=c++11
# source files
SRC_FILES := $(wildcard src/*.cpp) test.cpp
# rules
test: $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^
# cleaning
clean: ; rm test