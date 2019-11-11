#
# Filename:    SharedObjectBuildings
# Author:      Önder Görmez
# Dated:       December 01, 2018
# Decription:  Makefile for the Shared Object Buildings
#

################################################################################
#               USER SPECIFIC CONFIGURATION PART OF THE MAKEFILE               #
################################################################################

#
# User Configuration Area
# Please change this section for your specific needs. Such as
# other external libraries
#

USER_INC_DIR += -Ixxx
USER_LIBRARIES += -lxxx

################################################################################
#                   UTILITY DEFINITION PART OF THE MAKEFILE                    #
################################################################################

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

################################################################################
#                LIBRARY FOLDER DETECTION PART OF THE MAKEFILE                 #
################################################################################

LIB_NAME     = $(notdir $(shell dirname "$(CURDIR)"))
PROJECT_NAME = $(subst $(LIB_TAG),$(empty),$(LIB_NAME))

# Return space added value. For example "libPoissonPointProcess" to
# "lib PoissonPointProcess". Or return original value "Myproject" to "Myproject" 
SPACE_ADDED_LIB_NAME = $(subst $(LIB_TAG),$(LIB_TAG)$(space),$(LIB_NAME))

# New line for readable console output
$(info )

ifeq ($(word 1,$(SPACE_ADDED_LIB_NAME)),$(LIB_TAG))
    $(info Current parent folder "$(LIB_NAME)" is a library folder.)
else
    $(error                                                                    \
    $(newline) Current parent folder "$(LIB_NAME)" is not a library folder.    \
    $(newline) Library folder name must contain "lib" prefix!                  \
    $(newline) Example: "libPoissonPointProcess"                               \
    $(newline)                                                                 \
    )
endif

# New line for readable console output
$(info )

################################################################################
#                VERSION FOLDER DETECTION PART OF THE MAKEFILE                 #
################################################################################

# result: vX.Y or invalid folder name
CURRENT_DIR = $(notdir $(CURDIR))

# Return space added value. For example "v1.0" to "v 1.0".
# Or return original value "y.e" to "y.e" 
SPACE_ADDED_CURRENT_DIR = $(subst $(VER_TAG),$(VER_TAG)$(space),$(CURRENT_DIR))

ifneq ($(word 1,$(SPACE_ADDED_CURRENT_DIR)),$(VER_TAG))
    $(error                                                                    \
    $(newline) Current folder "$(CURRENT_DIR)" is not a library version folder.\
    $(newline) Library version folder name must contain "v" prefix!            \
    $(newline) Example: "v1.3" or "v2.8"                                       \
    $(newline)                                                                 \
    )
endif

#  Result: X.Y or empty value
VERSION     = $(word 2,$(SPACE_ADDED_CURRENT_DIR))

ifeq ($(VERSION),$(empty))
    $(error                                                                    \
    $(newline) Current folder "$(CURRENT_DIR)" is not a library version folder.\
    $(newline) Library version folder name must contain major and minor        \
    $(newline) verison number separated by dot!                                \
    $(newline) Example: "v1.3" or "v2.8"                                       \
    $(newline)                                                                 \
    )
endif

# If VERSION is contains a dot return dot
# else return null
IS_INCLUDE_DOT = $(findstring $(dot),$(VERSION))

ifeq ($(IS_INCLUDE_DOT),$(dot))
    $(info Current folder name "$(CURRENT_DIR)" is contains dot!)
else
    $(error                                                                    \
    $(newline) Current folder "$(CURRENT_DIR)" is not a library version folder.\
    $(newline) Library version folder name must contain dot for separating     \
    $(newline) major and minor version number!                                 \
    $(newline) Example: "v1.3" or "v2.8"                                       \
    $(newline)                                                                 \
    )
endif

# Result: X Y or just X
SPACE_ADDED_VERSION_NAME = $(subst $(dot),$(space),$(VERSION))

# result: X
MAJOR_VER = $(word 1,$(SPACE_ADDED_VERSION_NAME))

IS_VALID_MAJOR_VER = $(shell [ $(MAJOR_VER) -ge 0 ] && echo true)

ifeq ($(IS_VALID_MAJOR_VER),true)
    $(info Current folder name "$(CURRENT_DIR)" is contains valid major        \
    version number "$(MAJOR_VER)"!)
else
    $(error Major version number "$(MAJOR_VER)" is not a valid version number. \
    $(newline)   Library version folder name must contain                      \
                 valid major version number.                                   \
    $(newline)   Example: "v1.3" or "v2.8"                                     \
    $(newline))
endif

# result: Y
MINOR_VER = $(word 2,$(SPACE_ADDED_VERSION_NAME))

IS_VALID_MINOR_VER = $(shell [ $(MINOR_VER) -ge 0 ] && echo true)

ifeq ($(IS_VALID_MINOR_VER),true)
    $(info Current folder name "$(CURRENT_DIR)" is contains valid minor        \
    version number "$(MINOR_VER)"!)
else
    $(error Minor version number "$(MINOR_VER)" is not a valid version number. \
    $(newline)   Library version folder name must contain                      \
                 valid minor version number.                                   \
    $(newline)   Example: "v1.3" or "v2.8"                                     \
    $(newline))
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
# SO_DIR      := $(ROOT)/04-so

# Enter currently supported libraries include directories
INCLUDE_DIRS += -I$(CPP_COMPILED_LIBRARIES_INC_DIR)

# Names
HEADER_NAME  := $(PROJECT_NAME).hpp
SOURCE_NAME  := $(PROJECT_NAME).cpp
OBJ_NAME     := $(PROJECT_NAME).o
SO_NAME      := $(LIB_NAME).so.$(MAJOR_VER).$(MINOR_VER)
SO_SYM_LNK_1 := $(CPP_COMPILED_LIBRARIES_SO_DIR)/$(LIB_NAME).so.$(MAJOR_VER)
SO_SYM_LNK_2 := $(CPP_COMPILED_LIBRARIES_SO_DIR)/$(LIB_NAME).so

# Compilers
CPP      := g++

# Add "-D NDEBUG" flag to CPP_FLAGS, for release optimization
CPP_FLAGS := -Wall -fPIC -c -I$(INC_DIR) -std=c++11 -w

SRCS_CPP = $(SRC_DIR)/$(SOURCE_NAME)
OBJS_CPP = $(OBJ_DIR)/$(OBJ_NAME)

################################################################################
#                         RECIPES PART OF THE MAKEFILE                         #
################################################################################

library:
	$(CPP) $(CPP_FLAGS) $(SRCS_CPP) $(INCLUDE_DIRS) $(USER_INC_DIR)
	mv $(ROOT)/$(OBJ_NAME) $(OBJ_DIR)
	$(CPP) -shared -Wl,-soname,$(LIB_NAME).so.$(MAJOR_VER) -o $(SO_NAME) $(OBJS_CPP)
	cp $(INC_DIR)/$(HEADER_NAME) $(CPP_COMPILED_LIBRARIES_INC_DIR)
	mv $(SO_NAME) $(CPP_COMPILED_LIBRARIES_SO_DIR)
	ln -sf $(CPP_COMPILED_LIBRARIES_SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_1)
	ln -sf $(CPP_COMPILED_LIBRARIES_SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_2)
	sudo ldconfig

.PHONY: clean
clean:
	-rm $(CPP_COMPILED_LIBRARIES_INC_DIR)/$(HEADER_NAME)
	-rm -rf $(OBJ_DIR)/* $(CPP_COMPILED_LIBRARIES_SO_DIR)/$(SO_NAME) $(SO_SYM_LNK_1) $(SO_SYM_LNK_2)
	sudo ldconfig

################################################################################
#                             END OF THE MAKEFILE                              #
################################################################################