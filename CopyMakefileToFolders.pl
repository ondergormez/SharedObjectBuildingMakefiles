#!/usr/bin/perl
#
# Build DockShootingTest
#

use strict;
use warnings;
use Cwd;

my $CURRENT_DIR = cwd();
my $MAKEFILE = "Makefile";
my $LIB_RANDOM_PATH = "libRandomArray/v1.0/";
my $LIB_SORTING_PATH = "libSorting/v1.0/";
my $LIB_UTILITY_PATH = "libUtility/v1.0/";

printf("cp $MAKEFILE $LIB_RANDOM_PATH\n");
system(sprintf("cp $MAKEFILE $LIB_RANDOM_PATH\n"));

printf("cp $MAKEFILE $LIB_SORTING_PATH\n");
system(sprintf("cp $MAKEFILE $LIB_SORTING_PATH\n"));

printf("cp $MAKEFILE $LIB_UTILITY_PATH\n");
system(sprintf("cp $MAKEFILE $LIB_UTILITY_PATH\n"));
