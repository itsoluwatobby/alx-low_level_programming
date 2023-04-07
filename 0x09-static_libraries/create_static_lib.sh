#! /bin/bash
gcc -c *.c
ar rcc liball.a *.o
ranlib liball.a
