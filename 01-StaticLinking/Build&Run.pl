#!/usr/bin/perl
#
# Build StaticLinking
#

use strict;
use warnings;

system(sprintf("clear"));

# This part builds the CalculateArea static library.
printf("g++ -c -Wall -fPIC -std=c++11 CalculateArea.cpp -o CalculateArea.o\n");
system(sprintf("g++ -c -Wall -fPIC -std=c++11 CalculateArea.cpp -o CalculateArea.o"));

printf("ar rcs libCalculateArea.a CalculateArea.o\n");
system(sprintf("ar rcs libCalculateArea.a CalculateArea.o"));

# This part builds the program with the required static library.
printf("g++ -Wall -fPIC -std=c++11 main.cpp -L. -lCalculateArea -o prog.elf\n");
system(sprintf("g++ -Wall -fPIC -std=c++11 main.cpp -L. -lCalculateArea -o prog.elf"));

printf("./prog.elf\n");
system(sprintf("./prog.elf"));