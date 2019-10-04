#!/usr/bin/perl
#
# Build DynamicLinking
#

use strict;
use warnings;

system(sprintf("clear"));

printf("rm -rf *.o *.elf\n\n");
system(sprintf("rm -rf *.o *.elf"));

# This part builds the my_strcmp file.
printf("g++ -c -Wall -std=c++11 my_strcmp.cpp -o my_strcmp.o\n");
system(sprintf("g++ -c -Wall -std=c++11 my_strcmp.cpp -o my_strcmp.o"));
printf("my_strcmp.o file created!\n\n");

# This part builds the program with the required .o files.
printf("g++ -Wall -std=c++11 main.cpp my_strcmp.o -o prog.elf\n\n");
system(sprintf("g++ -Wall -std=c++11 main.cpp my_strcmp.o -o prog.elf"));

printf("./prog.elf\n");
system(sprintf("./prog.elf"));