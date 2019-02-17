#
# Filename:    SharedObjectBuildings
# Author:      Önder Görmez
# Dated:       December 01, 2018
# Decription:  Makefile for the Shared Object Buildings
#
LIB_TAG = lib
VER_TAG = v
comma:= ,
empty:=
space:= $(empty) $(empty)
LIB_NAME     = $(notdir $(shell dirname $(CURDIR)))
PROJECT_NAME = $(subst $(LIB_TAG),$(empty),$(LIB_NAME))

CURRENT_DIR = $(notdir $(CURDIR))
VERSION = $(subst $(VER_TAG),$(empty),$(CURRENT_DIR))
MAJOR_VER = 1
MINOR_VER = 0

# Directories
ROOT         = .
MAIN_DIR    := $(ROOT)
INC_DIR     := $(ROOT)/01-inc
SRC_DIR     := $(ROOT)/02-src
OBJ_DIR     := $(ROOT)/03-obj
#SO_DIR      := $(ROOT)/04-so
PUBLIC_INC_DIR := /usr/local/lib/ExternalLibraries/01-inc
SO_DIR      := /usr/local/lib/ExternalLibraries/02-so

# Libraries
LIB_INC_DIR := ../../libUtility/v1.0/01-inc
#LIB_SO_DIR  := ../../libUtility/v1.0/04-so/Utility
USED_LIBRARIES := -lUtility

# Names
HEADER_NAME  := $(PROJECT_NAME).hpp
SOURCE_NAME  := $(PROJECT_NAME).cpp
OBJ_NAME     := $(PROJECT_NAME).o
SO_NAME      := $(LIB_NAME).so.$(MAJOR_VER).$(MINOR_VER)
SO_SYM_LNK_1 := $(SO_DIR)/$(LIB_NAME).so.$(MAJOR_VER)
SO_SYM_LNK_2 := $(SO_DIR)/$(LIB_NAME).so

# Compilers
CPP      := g++

# Add this flag to CPPFLAGS, for release optimization "-D NDEBUG"
CPPFLAGS := -Wall -fPIC -c -I$(INC_DIR) -std=c++11 -w

SRCS_CPP = $(SRC_DIR)/$(SOURCE_NAME)
OBJS_CPP = $(OBJ_DIR)/$(OBJ_NAME)

main:
	$(CPP) $(CPPFLAGS) $(SRCS_CPP) -I$(LIB_INC_DIR)
	mv $(ROOT)/$(OBJ_NAME) $(OBJ_DIR)
	$(CPP) -shared -Wl,-soname,$(LIB_NAME).so.$(MAJOR_VER) -o $(SO_NAME) $(OBJS_CPP)
	sudo mkdir -p $(PUBLIC_INC_DIR)
	sudo cp $(INC_DIR)/$(HEADER_NAME) $(PUBLIC_INC_DIR)
	sudo mkdir -p $(SO_DIR)
	sudo mv $(SO_NAME) $(SO_DIR)
	sudo ln -sf $(SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_1)
	sudo ln -sf $(SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_2)
	sudo sh -c "echo '$(SO_DIR)' > '/etc/ld.so.conf.d/$(LIB_NAME).conf'"
	sudo ldconfig

.PHONY: clean
clean:
	sudo rm $(PUBLIC_INC_DIR)/$(HEADER_NAME)
	sudo rm -rf $(OBJ_DIR)/* $(SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_1) $(SO_SYM_LNK_2)
	sudo rm /etc/ld.so.conf.d/$(LIB_NAME).conf
