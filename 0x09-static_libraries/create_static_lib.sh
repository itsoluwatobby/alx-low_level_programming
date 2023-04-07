#! /bin/bash
gcc -c ./cfiles/*.c
ar rcc liball.a ./cfiles/*.o
ranlib liball.a
