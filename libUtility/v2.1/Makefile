#
# Filename:    DynamicLibraryImplementation
# Author:      Önder Görmez
# Dated:       December 05, 2017
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

# Names
OBJ_NAME     := libUtility.o
SO_NAME      := libUtility.so.2.1
SO_SYM_LNK_1 := /lib/libUtility.so.2
SO_SYM_LNK_2 := /lib/libUtility.so

CPP      := g++
#CC       := gcc

# Add this flag to CPPFLAGS, for release optimization "-D NDEBUG"
CPPFLAGS := -Wall -fPIC -c -I$(INC_DIR) -std=c++11 -w

SRCS_CPP = $(SRC_DIR)/Utility.cpp

OBJS_CPP = $(ROOT)/Utility.o

main:
	$(CPP) $(CPPFLAGS) $(SRCS_CPP)
	$(CPP) -shared -Wl,-soname,libUtility.so.2 -o $(SO_NAME) $(OBJS_CPP)
	mv $(OBJS_CPP) $(OBJ_DIR)
	sudo mv $(SO_NAME) $(SO_DIR)
	sudo ln -sf $(SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_1)
	sudo ln -sf $(SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_2)