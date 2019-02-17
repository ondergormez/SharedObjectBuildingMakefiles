#
# Filename:    DynamicLibraryImplementation
# Author:      Önder Görmez
# Dated:       December 01, 2018
# Decription:  Makefile for the DynamicLibraryImplementation
#

LIB_NAME     = libSorting
NAME 		 = Sorting.hpp
# Directories
ROOT         = .
MAIN_DIR    := $(ROOT)
INC_DIR     := $(ROOT)/01-inc
SRC_DIR     := $(ROOT)/02-src
OBJ_DIR     := $(ROOT)/03-obj
#SO_DIR      := $(ROOT)/04-so
#SO_DIR  := /lib
PUBLIC_INC_DIR := /usr/local/lib/ExternalLibraries/01-inc
SO_DIR      := /usr/local/lib/ExternalLibraries/02-so

# Libraries
LIB_INC_DIR := 

# Names
OBJ_NAME     := Sorting.o
SO_NAME      := $(LIB_NAME).so.1.0
SO_SYM_LNK_1 := $(SO_DIR)/$(LIB_NAME).so.1
SO_SYM_LNK_2 := $(SO_DIR)/$(LIB_NAME).so

# Compilers
CPP      := g++

# Add this flag to CPPFLAGS, for release optimization "-D NDEBUG"
CPPFLAGS := -Wall -fPIC -c -I$(INC_DIR) -std=c++11 -w

SRCS_CPP = $(SRC_DIR)/Sorting.cpp
OBJS_CPP = $(OBJ_DIR)/$(OBJ_NAME)

main:
	$(CPP) $(CPPFLAGS) $(SRCS_CPP) $(LIB_INC_DIR)
	mv $(ROOT)/$(OBJ_NAME) $(OBJ_DIR)
	$(CPP) -shared -Wl,-soname,$(LIB_NAME).so.1 -o $(SO_NAME) $(OBJS_CPP)
	sudo mkdir -p $(PUBLIC_INC_DIR)
	sudo cp $(INC_DIR)/$(NAME) $(PUBLIC_INC_DIR)
	sudo mkdir -p $(SO_DIR)
	sudo mv $(SO_NAME) $(SO_DIR)
	sudo ln -sf $(SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_1)
	sudo ln -sf $(SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_2)
	sudo sh -c "echo '$(SO_DIR)' > '/etc/ld.so.conf.d/$(LIB_NAME).conf'"
	sudo ldconfig

.PHONY: clean
clean:
	sudo rm $(PUBLIC_INC_DIR)/$(NAME)
	sudo rm -rf $(OBJ_DIR)/* $(SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_1) $(SO_SYM_LNK_2)
	sudo rm /etc/ld.so.conf.d/$(LIB_NAME).conf