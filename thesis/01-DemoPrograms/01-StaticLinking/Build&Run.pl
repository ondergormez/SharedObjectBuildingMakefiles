#!/usr/bin/perl
#
# Build StaticLinking
#

use strict;
use warnings;

system(sprintf("clear"));

printf("rm -rf *.a *.o *.elf\n\n");
system(sprintf("rm -rf *.a *.o *.elf"));

# This part builds the CalculateArea static library.
printf("g++ -c -Wall -std=c++11 CalculateArea.cpp -o CalculateArea.o\n");
system(sprintf("g++ -c -Wall -std=c++11 CalculateArea.cpp -o CalculateArea.o"));
printf("CalculateArea.o file created!\n\n");

printf("ar rcs libCalculateArea.a CalculateArea.o\n");
system(sprintf("ar rcs libCalculateArea.a CalculateArea.o"));
printf("libCalculateArea.a file created!\n\n");

printf("ar -t libCalculateArea.a\n");
system(sprintf("ar -t libCalculateArea.a"));
printf("\n");

# This part builds the program with the required static library.
printf("g++ -Wall -std=c++11 main.cpp -L. -lCalculateArea -o prog.elf\n\n");
system(sprintf("g++ -Wall -std=c++11 main.cpp -L. -lCalculateArea -o prog.elf"));

printf("./prog.elf\n");
system(sprintf("./prog.elf"));