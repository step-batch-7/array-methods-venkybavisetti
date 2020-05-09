#! /bin/bash
mkdir -p .bin

rm -rf *.o
gcc -c *.c
gcc -o .bin/a.out *.o 
.bin/a.out
rm -rf *.o

# #! /bin/bash

# directory=$1

# mkdir -p outputs
# rm -rf $directory/*.o
# gcc -c array.c $directory/*.c
# gcc -o outputs/a.out *.o && outputs/a.out
# rm -rf *.o