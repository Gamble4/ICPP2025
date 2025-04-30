#!/bin/bash

# useful flags:  -Wall -Werror
uniflags="-Wall -Wextra -pedantic"

#get filename without extension 
if [ "${1:(-2)}" == ".c" ]
then 
  fname="${1:0:(-2)}"
  compiler=clang
  specflags="-std=c99"
elif [ "${1:(-4)}" == ".cpp" ]
then
  fname="${1:0:(-4)}"
  compiler=clang++
  specflags="-std=c++17"
else
  echo "filetype not supported"
  exit "-1"
fi

outfile="$fname.out"
$compiler $uniflags $specflags $1 -o $outfile -lm
./$outfile
# not necessary, here just to keep things more organised in folder
#rm $1

