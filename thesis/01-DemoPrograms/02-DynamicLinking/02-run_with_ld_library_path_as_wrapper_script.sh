#!/bin/sh
# usage:
# prompt> echo $LD_LIBRARY_PATH
# prompt> ./02-run_with_ld_library_path_as_wrapper_script.sh
# prompt> echo $LD_LIBRARY_PATH
# See that the value of LD_LIBRARY_PATH environment variable has not changed.

LD_LIBRARY_PATH=/media/sf_SharedFolder/Projects/MyProjects/SharedObjectBuildingMakefiles/02-DynamicLinking:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH
exec ./prog.elf