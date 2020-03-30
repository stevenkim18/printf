#! /bin/bash

cat main.c

echo "=========================================gcc================================================================="
cc main.c -L. libftprintf.a
./a.out | cat -e


echo -e "\n=========================================clang================================================================="
clang -Wall -Werror -Wextra main.c -L. libftprintf.a
./a.out | cat -e

