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

LIB_INC_DIR += -I../libRandomArray/v1.0/01-inc
LIB_INC_DIR += -I../libSorting/v1.0/01-inc
LIB_INC_DIR += -I../LibUtility/v1.0/01-inc

#LIB_SO_DIR  += -L../libRandomArray/v1.0/04-so/RandomArray
#LIB_SO_DIR  += -L../libUtility/v1.0/04-so/Utility

USED_LIBRARIES += -lUtility
USED_LIBRARIES += -lRandomArray
USED_LIBRARIES += -lSorting

CPP      := g++
#CC       := gcc

# Add this flag to CPPFLAGS, for release optimization "-D NDEBUG"
CPPFLAGS := -Wall -fPIC -std=c++11 -w

SRCS_CPP = $(SRC_DIR)/main.cpp

OBJS_CPP = $(ROOT)/main.o

main:
	$(CPP) $(CPPFLAGS) $(SRCS_CPP) -I$(INC_DIR) $(LIB_INC_DIR) $(USED_LIBRARIES) -o prog.elf