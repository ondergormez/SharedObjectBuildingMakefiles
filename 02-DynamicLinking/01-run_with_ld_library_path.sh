#!/bin/sh
# usage:
# Line by line copy the contents of this file to the command line and run.
clear
./prog.elf
ldd prog.elf | grep MyString
echo $LD_LIBRARY_PATH
LD_LIBRARY_PATH=/media/sf_SharedFolder/Projects/MyProjects/SharedObjectBuildingMakefiles/02-DynamicLinking:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH
echo $LD_LIBRARY_PATH
ldd prog.elf | grep MyString
./prog.elf
unset LD_LIBRARY_PATH
./prog.elf
