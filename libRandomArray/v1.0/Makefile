#
# Filename:    DynamicLibraryImplementation
# Author:      Önder Görmez
# Dated:       December 01, 2018
# Decription:  Makefile for the DynamicLibraryImplementation
#


# Directories
ROOT         = .
MAIN_DIR    := $(ROOT)
INC_DIR     := $(ROOT)/01-inc
SRC_DIR     := $(ROOT)/02-src
OBJ_DIR     := $(ROOT)/03-obj
#SO_DIR      := $(ROOT)/04-so
SO_DIR  := /lib

# Libraries
LIB_INC_DIR := ../../libUtility/v1.0/01-inc
#LIB_SO_DIR  := ../../libUtility/v1.0/04-so/Utility
USED_LIBRARIES := -lUtility

# Names
OBJ_NAME     := Array.o
SO_NAME      := libRandomArray.so.1.0
SO_SYM_LNK_1 := $(SO_DIR)/libRandomArray.so.1
SO_SYM_LNK_2 := $(SO_DIR)/libRandomArray.so

# Compilers
CPP      := g++
#CC       := gcc

# Add this flag to CPPFLAGS, for release optimization "-D NDEBUG"
CPPFLAGS := -Wall -fPIC -c -I$(INC_DIR) -std=c++11 -w

SRCS_CPP = $(SRC_DIR)/Array.cpp
OBJS_CPP = $(OBJ_DIR)/$(OBJ_NAME)

#SRCS_CPP = $(SRC_DIR)/$(wildcard *.cpp)
#OBJECTS = $(SOURCES:.cpp=.o)
#HEADERS = $(SRC_DIR)/$(wildcard *.hpp)

main:
	$(CPP) $(CPPFLAGS) $(SRCS_CPP) -I$(LIB_INC_DIR)
	mv $(ROOT)/$(OBJ_NAME) $(OBJ_DIR)
	$(CPP) -shared -Wl,-soname,libRandomArray.so.1 -o $(SO_NAME) $(OBJS_CPP)
	sudo mv $(SO_NAME) $(SO_DIR)
	sudo ln -sf $(SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_1)
	sudo ln -sf $(SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_2)

.PHONY: clean
clean:
	-rm -rf $(OBJ_DIR)/* $(SO_DIR)/*