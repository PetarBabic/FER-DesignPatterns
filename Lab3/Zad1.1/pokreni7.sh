#!/bin/bash

rm *.so
rm *.out
rm *.o

gcc -Wno-deprecated-non-prototype -c myfactory.c animal.c
g++ main2.c myfactory.o animal.o
gcc -shared -fPIC tiger.c -o tiger.so
gcc -shared -fPIC parrot.c -o parrot.so
./a.out tiger mirko parrot modrobradi
