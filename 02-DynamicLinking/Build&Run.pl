#!/usr/bin/perl
#
# Build DynamicLinking
#

use strict;
use warnings;

system(sprintf("clear"));

# get script name
my $ScriptName = $0;
my $ArgumentCount = $#ARGV + 1;
my $BuildForRpath = "build_for_rpath";
my $BuildFor_LD_LIBRARY_PATH = "build_for_LD_LIBRARY_PATH";

sub printUsage {
    printf("Usage:\n");
    printf("$ScriptName $BuildForRpath\n");
    printf("$ScriptName $BuildFor_LD_LIBRARY_PATH\n");
}

if ($ArgumentCount != 1) {
    printf("Wrong argument count: $ArgumentCount!\n");
    printUsage();
    exit;
}
elsif (($ARGV[0] ne $BuildForRpath) && ($ARGV[0] ne $BuildFor_LD_LIBRARY_PATH)) {
    print "\"$ARGV[0]\" wrong argument!\n";
    printUsage();
    exit;
}

printf("rm -rf *.o *.so *.elf\n\n");
system(sprintf("rm -rf *.o *.so *.elf"));

# This part builds the my_strcmp.o file.
printf("g++ -c -Wall -fPIC -std=c++11 my_strcmp.cpp -o my_strcmp.o\n");
system(sprintf("g++ -c -Wall -fPIC -std=c++11 my_strcmp.cpp -o my_strcmp.o"));
printf("my_strcmp.o file created!\n\n");

# This part builds the my_strlen.o file.
printf("g++ -c -Wall -fPIC -std=c++11 my_strlen.cpp -o my_strlen.o\n");
system(sprintf("g++ -c -Wall -fPIC -std=c++11 my_strlen.cpp -o my_strlen.o"));
printf("my_strlen.o file created!\n\n");

# This part create libMyStringOp.so shared library file.
printf("g++ -shared -o libMyStringOp.so my_strcmp.o my_strlen.o\n");
system(sprintf("g++ -shared -o libMyStringOp.so my_strcmp.o my_strlen.o"));
printf("libMyStringOp.so library file created!\n\n");

if ($ARGV[0] eq $BuildForRpath) {

}
elsif ($ARGV[0] eq $BuildFor_LD_LIBRARY_PATH) {
    # This part builds the program with the required .o files.
    printf("g++ -Wall -std=c++11 main.cpp -L./ -lMyStringOp -o prog.elf\n");
    system(sprintf("g++ -Wall -std=c++11 main.cpp -L./ -lMyStringOp -o prog.elf"));
}
    printf("prog.elf file created!\n\n");

printf("./prog.elf\n");
system(sprintf("./prog.elf"));
printf("\n");