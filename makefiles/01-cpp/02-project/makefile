#
# Filename:    SharedObjectBuildings
# Author:      Önder Görmez
# Dated:       December 01, 2018
# Decription:  Makefile for the SharedObjectBuildings
#

################################################################################
#               USER SPECIFIC CONFIGURATION PART OF THE MAKEFILE               #
################################################################################

#
# User Configuration Area
# Please change this section for your specific needs. Such as
# other external libraries
#

################################################################################
#                   UTILITY DEFINITION PART OF THE MAKEFILE                    #
################################################################################

#
# Generic Area
# Please don't change this section for properly working.
#

PROJECT_TAG = prj
empty:= 
space:= $(empty) $(empty)
define newline


endef

################################################################################
#                PROJECT FOLDER DETECTION PART OF THE MAKEFILE                 #
################################################################################

FOLDER_NAME     = $(notdir $(shell pwd))
PROJECT_NAME = $(subst $(PROJECT_TAG),$(empty),$(FOLDER_NAME))

# Return space added value. For example "prjSortAndDisplay" to
# "prj SortAndDisplay". Or return original value "Myproject" to "Myproject" 
SPACE_ADDED_FOLDER_NAME = $(subst $(PROJECT_TAG),$(PROJECT_TAG)$(space),       \
                            $(FOLDER_NAME))

# New line for readable console output
$(info )

ifeq ($(word 1,$(SPACE_ADDED_FOLDER_NAME)),$(PROJECT_TAG))
    $(info Current folder "$(FOLDER_NAME)" is a project folder.)
else
    $(error                                                                    \
    $(newline) Current folder "$(FOLDER_NAME)" is not a project folder.        \
    $(newline) Project folder name must contain "$(PROJECT_TAG)" prefix!       \
    $(newline) Example: "$(PROJECT_TAG)SortAndDisplay"                         \
    $(newline)                                                                 \
    )
endif

# New line for readable console output
$(info )

################################################################################
#             NECESSARY SUBFOLDERS DETECTION PART OF THE MAKEFILE              #
################################################################################

# Directories
ROOT         = .
MAIN_DIR    := $(ROOT)
INC_DIR     := $(ROOT)/01-inc
SRC_DIR     := $(ROOT)/02-src
OBJ_DIR     := $(ROOT)/03-obj

# result: xx/yy/zz/abc.hpp xx/yy/zz/def.hpp
FILES_WITH_PATH_AND_EXTENSION = $(shell find $(CPP_COMPILED_LIBRARIES_INC_DIR) \
                                  -name '*.hpp')
# result: abc.hpp def.hpp
FILES_WITH_EXTENSION = $(notdir $(FILES_WITH_PATH_AND_EXTENSION))
# result: abc def
FILE_NAMES = $(basename $(FILES_WITH_EXTENSION))
# result: -labc -ldef
USED_LIBRARIES = $(addprefix -l, $(FILE_NAMES))

$(info Shared object libraries in this system: $(FILE_NAMES))
# New line for readable console output
$(info )

CPP      := g++

# Add "-D NDEBUG" flag to CPP_FLAGS, for release optimization
CPP_FLAGS := -Wall -fPIC -std=c++11 -w

SRCS_CPP = $(SRC_DIR)/main.cpp

OBJS_CPP = $(ROOT)/main.o

################################################################################
#                         RECIPES PART OF THE MAKEFILE                         #
################################################################################

main:
	$(CPP) $(CPP_FLAGS) $(SRCS_CPP)                                            \
	-I$(INC_DIR) -I$(CPP_COMPILED_LIBRARIES_INC_DIR)                           \
	-ldl -L$(CPP_COMPILED_LIBRARIES_SO_DIR) $(USED_LIBRARIES)                  \
	-o $(PROJECT_NAME).elf

.PHONY: clean
clean:
	-rm -rf $(OBJ_DIR)/*
	-rm -rf $(PROJECT_NAME).elf

################################################################################
#                             END OF THE MAKEFILE                              #
################################################################################