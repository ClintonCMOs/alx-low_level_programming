#!/bin/bash
gcc -Wall -Wextra -Werror -pedentic -c -fPIC -c *.c
gcc -shared -o liball.so *.o
export LD_LIBRAY_PATH=.:$LD_LIBRAY_PATH
