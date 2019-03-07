#
# Filename:    SharedObjectBuildings
# Author:      Önder Görmez
# Dated:       December 01, 2018
# Decription:  Makefile for the Shared Object Buildings
#

#
# User Configuration Area
# Please change this section for your specific needs. Such as
# other external libraries
#

USER_INC_DIR += -Ixxx
USER_LIBRARIES += -lxxx

#
# Generic Area
# Please don't change this section for properly working.
#

LIB_TAG = lib
VER_TAG = v
dot:= .
empty:= 
space:= $(empty) $(empty)
define newline


endef

LIB_NAME     = $(notdir $(shell dirname $(CURDIR)))
PROJECT_NAME = $(subst $(LIB_TAG),$(empty),$(LIB_NAME))


# Return space added value. For example "libPoissonPointProcess" to "lib PoissonPointProcess".
# Or return original value "Myproject" to "Myproject" 
SPACE_ADDED_LIB_NAME = $(subst $(LIB_TAG),$(LIB_TAG)$(space),$(LIB_NAME))

# If SPACE_ADDED_LIB_NAME is contains a lib name return LIB_TAG
# else return null
IS_LIB_FOLDER = $(findstring $(LIB_TAG),$(SPACE_ADDED_LIB_NAME))

ifeq ($(IS_LIB_FOLDER),$(LIB_TAG))
    $(info Current parent folder is a "$(PROJECT_NAME)" library folder.)
else
    $(error Current parent folder "$(LIB_NAME)" is not a library folder.                \
        $(newline)                 Library folder name must be include "lib" prefix!    \
        $(newline)                 Example: "libPoissonPointProcess"                    \
        $(newline))
endif

CURRENT_DIR = $(notdir $(CURDIR))#                          result: vX.Y
VERSION     = $(subst $(VER_TAG),$(empty),$(CURRENT_DIR))#  result: X.Y
TEMP        = $(subst $(dot),$(space),$(VERSION))#          result: X Y
MAJOR_VER   = $(word 1,$(TEMP))#                            result: X
MINOR_VER = $(word 2,$(TEMP))#                              result: Y

# Directories
ROOT         = .
MAIN_DIR    := $(ROOT)
INC_DIR     := $(ROOT)/01-inc
SRC_DIR     := $(ROOT)/02-src
OBJ_DIR     := $(ROOT)/03-obj
#SO_DIR      := $(ROOT)/04-so

#Enter currently supported libraries include directories
INCLUDE_DIRS += -I/usr/local/lib/ExternalLibraries/01-inc

#Enter external libraries current location for copying new header and so file
LIBRARIES_INC_DIR := /usr/local/lib/ExternalLibraries/01-inc
LIBRARIES_SO_DIR  := /usr/local/lib/ExternalLibraries/02-so

# Names
HEADER_NAME  := $(PROJECT_NAME).hpp
SOURCE_NAME  := $(PROJECT_NAME).cpp
OBJ_NAME     := $(PROJECT_NAME).o
SO_NAME      := $(LIB_NAME).so.$(MAJOR_VER).$(MINOR_VER)
SO_SYM_LNK_1 := $(LIBRARIES_SO_DIR)/$(LIB_NAME).so.$(MAJOR_VER)
SO_SYM_LNK_2 := $(LIBRARIES_SO_DIR)/$(LIB_NAME).so

# Compilers
CPP      := g++

# Add "-D NDEBUG" flag to CPP_FLAGS, for release optimization
CPP_FLAGS := -Wall -fPIC -c -I$(INC_DIR) -std=c++11 -w

SRCS_CPP = $(SRC_DIR)/$(SOURCE_NAME)
OBJS_CPP = $(OBJ_DIR)/$(OBJ_NAME)

main:
	$(CPP) $(CPP_FLAGS) $(SRCS_CPP) $(INCLUDE_DIRS) $(USER_INC_DIR)
	mv $(ROOT)/$(OBJ_NAME) $(OBJ_DIR)
	$(CPP) -shared -Wl,-soname,$(LIB_NAME).so.$(MAJOR_VER) -o $(SO_NAME) $(OBJS_CPP)
	sudo mkdir -p $(LIBRARIES_INC_DIR)
	sudo cp $(INC_DIR)/$(HEADER_NAME) $(LIBRARIES_INC_DIR)
	sudo mkdir -p $(LIBRARIES_SO_DIR)
	sudo mv $(SO_NAME) $(LIBRARIES_SO_DIR)
	sudo ln -sf $(LIBRARIES_SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_1)
	sudo ln -sf $(LIBRARIES_SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_2)
	sudo sh -c "echo '$(LIBRARIES_SO_DIR)' > '/etc/ld.so.conf.d/$(LIB_NAME).conf'"
	sudo ldconfig

.PHONY: clean
clean:
	sudo rm $(LIBRARIES_INC_DIR)/$(HEADER_NAME)
	sudo rm -rf $(OBJ_DIR)/* $(LIBRARIES_SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_1) $(SO_SYM_LNK_2)
	sudo rm /etc/ld.so.conf.d/$(LIB_NAME).conf