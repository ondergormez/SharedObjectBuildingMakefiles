#!/bin/sh
# usage:
# Line by line copy the contents of this file to the command line and run.
clear
./prog.elf
echo $LD_LIBRARY_PATH
LD_LIBRARY_PATH=/media/sf_SharedFolder/Projects/MyProjects/SharedObjectBuildingMakefiles/02-DynamicLinking:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH
./prog.elf
echo $LD_LIBRARY_PATH
unset LD_LIBRARY_PATH
