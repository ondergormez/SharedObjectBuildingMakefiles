#!/bin/sh
clear
echo '$LD_LIBRARY_PATH'
echo $LD_LIBRARY_PATH
echo

echo ./prog.elf
./prog.elf
echo
echo

echo 'env LD_LIBRARY_PATH=/media/sf_SharedFolder/Projects/MyProjects/SharedObjectBuildingMakefiles/02-DynamicLinking:$LD_LIBRARY_PATH ./prog.elf'
env LD_LIBRARY_PATH=/media/sf_SharedFolder/Projects/MyProjects/SharedObjectBuildingMakefiles/02-DynamicLinking:$LD_LIBRARY_PATH ./prog.elf
echo

echo '$LD_LIBRARY_PATH'
echo $LD_LIBRARY_PATH
echo