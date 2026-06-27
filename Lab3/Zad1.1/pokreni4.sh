#!/bin/bash

rm *.so
rm *.out
rm *.o

gcc -Wno-deprecated-non-prototype main.c myfactory.c -ldl
gcc -shared -fPIC tiger.c -o tiger.so
gcc -shared -fPIC parrot.c -o parrot.so
./a.out tiger mirko parrot modrobradi
