#
# Filename:    SharedObjectBuildings
# Author:      Önder Görmez
# Dated:       December 01, 2018
# Decription:  Makefile for the SharedObjectBuildings
#

# Directories
ROOT         = .
MAIN_DIR    := $(ROOT)
INC_DIR     := $(ROOT)/01-inc
SRC_DIR     := $(ROOT)/02-src
OBJ_DIR     := $(ROOT)/03-obj

FILES_WITH_PATH_AND_EXTENSION = $(shell find $(CPP_COMPILED_LIBRARIES_INC_DIR) -name '*.hpp')#   result: xx/yy/zz/abc.hpp xx/yy/zz/def.hpp
FILES_WITH_EXTENSION = $(notdir $(FILES_WITH_PATH_AND_EXTENSION))#                  result: abc.hpp def.hpp
FILE_NAMES = $(basename $(FILES_WITH_EXTENSION))#                                   result: abc def
USED_LIBRARIES = $(addprefix -l, $(FILE_NAMES))#                                    result: -labc -ldef

CPP      := g++

# Add "-D NDEBUG" flag to CPP_FLAGS, for release optimization
CPP_FLAGS := -Wall -fPIC -std=c++11 -w

SRCS_CPP = $(SRC_DIR)/main.cpp

OBJS_CPP = $(ROOT)/main.o

main:
	$(CPP) $(CPP_FLAGS) $(SRCS_CPP) -I$(INC_DIR) -I$(CPP_COMPILED_LIBRARIES_INC_DIR) -L$(CPP_COMPILED_LIBRARIES_SO_DIR) $(USED_LIBRARIES) -ldl -o prog.elf

test:
	$(USED_LIBRARIES)
