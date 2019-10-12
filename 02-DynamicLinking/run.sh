#!/bin/sh
LD_LIBRARY_PATH=/media/sf_SharedFolder/Projects/MyProjects/SharedObjectBuildingMakefiles/02-DynamicLinking:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH
exec ./prog.elf $@

