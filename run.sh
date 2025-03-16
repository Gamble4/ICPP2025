#!/bin/bash

# useful flags:  -Wall -Werror
flags="-std=c++17 -Wall -pedantic"

#get filename without extension 
fname="${1:0:(-4)}"
outfile="$fname.out"
clang++ $flags $1 -o $outfile
./$outfile
# not necessary, here just to keep things more organised in folder
#rm $1

