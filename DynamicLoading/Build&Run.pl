#!/usr/bin/perl
#
# Build DynamicLoading
#

use strict;
use warnings;
use Cwd;

my $CURRENT_DIR = cwd();
my $OUTPUT_DIR = "./03-obj";
my $OUTPUT_NAME = "prog.elf";
my $FILE_NAME_TO_BE_PLOTTED = "sine_wave_timeline_commands.txt";
my $IMAGE_NAME_TO_BE_SHOWED = "sine_wave_timeline.png";

system(sprintf("clear"));

printf("rm $OUTPUT_DIR/*\n");
system(sprintf("rm $OUTPUT_DIR/*"));
printf("All files in $OUTPUT_DIR folder are deleted!\n\n");

system(sprintf("make"));
printf("Compilation finished.\n\n");

chdir "$OUTPUT_DIR";
system(sprintf("./$OUTPUT_NAME"));
system(sprintf("gnuplot < $FILE_NAME_TO_BE_PLOTTED"));
system(sprintf("gwenview $IMAGE_NAME_TO_BE_SHOWED"));
chdir "$CURRENT_DIR";