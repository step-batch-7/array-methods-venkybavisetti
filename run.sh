#! /bin/bash
mkdir -p .bin

rm -rf *.o
gcc -c *.c
gcc -o .bin/a.out *.o 
.bin/a.out
rm -rf *.o