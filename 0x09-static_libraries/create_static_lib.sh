#! /bin/bash

echo "Running gcc on all *.c files"
gcc -Wall -pedantic -Werror -Wextra -c *.c
ar rcc liball.a *.o
ranlib liball.a
echo "task completed"
