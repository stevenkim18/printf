#! /bin/bash

cat main.c
cc main.c -L. libftprintf.a
./a.out | cat -e
