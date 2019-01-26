#
# Filename:    DynamicLibraryImplementation
# Author:      Önder Görmez
# Dated:       November 28, 2017
# Decription:  Makefile for the DynamicLibraryImplementation
#


# Directories
ROOT         = .
MAIN_DIR    := $(ROOT)
INC_DIR     := $(ROOT)/01-inc
SRC_DIR     := $(ROOT)/02-src
OBJ_DIR     := $(ROOT)/03-obj
#SO_DIR      := $(ROOT)/04-so #Write Access problem in VirtualBox Shared Folder
SO_DIR  := /lib

LIB_INC_DIR := ../../LibUtility/v1.0/01-inc
LIB_SO_DIR  := ../../LibUtility/v1.0/04-so


# Names
OBJ_NAME     := libMatrix.o
SO_NAME      := libMatrix.so.1.5
SO_SYM_LNK_1 := /lib/libMatrix.so.1
SO_SYM_LNK_2 := /lib/libMatrix.so

CPP      := g++
#CC       := gcc

# Add this flag to CPPFLAGS, for release optimization "-D NDEBUG"
CPPFLAGS := -Wall -fPIC -c -I$(INC_DIR) -std=c++11 -w

SRCS_CPP = $(SRC_DIR)/Matrix.cpp

OBJS_CPP = $(ROOT)/Matrix.o

main:
	$(CPP) $(CPPFLAGS) $(SRCS_CPP) -I$(LIB_INC_DIR)
	$(CPP) -shared -Wl,-soname,libMatrix.so.1 -o $(SO_NAME) $(OBJS_CPP) -lUtility
	mv $(OBJS_CPP) $(OBJ_DIR)
	sudo mv $(SO_NAME) $(SO_DIR)
	sudo ln -sf $(SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_1)
	sudo ln -sf $(SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_2)