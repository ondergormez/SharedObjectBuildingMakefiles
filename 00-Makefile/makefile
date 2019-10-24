#
# Project    : SharedObjectBuildings
# Author     : Önder Görmez
# Dated      : October 22, 2019
# Decription : Makefile for the simple hello world program.
#

OUTPUT_FILE = hello.elf
INSTALL_DIR = bin
COMPILER = g++

# Default target
.PHONY: all
all: $(OUTPUT_FILE)

# Build hello.elf from main.cpp
$(OUTPUT_FILE): main.cpp
	$(COMPILER) -o $(OUTPUT_FILE) main.cpp

# Copy hello.elf to the bin directory
.PHONY: install
install:
	mkdir -p $(INSTALL_DIR)
	cp -p $(OUTPUT_FILE) $(INSTALL_DIR)

# Delete hello.elf
.PHONY: clean
clean:
	rm -f $(OUTPUT_FILE)