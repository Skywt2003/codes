#!/bin/bash

file="defense"
L=1
R=25

g++ $file.cpp -o $file

while [ $L -le $R ]
do
    echo -e "\033[33m Running on test $L... \033[0m"
    /usr/bin/time -f %U ./$file < $file$L.in > $file$L.out 2>tmp
    tm=`cat tmp`
    rm tmp
    if diff $file$L.out $file$L.ans; then
        echo -e -n "\033[33m Test $L... \033[0m"
        echo -e "\033[42;30m Accepted Time: $tm s\033[0m"
        rm $file$L.out
    else
        echo -e -n "\033[33m Test $L... \033[0m"
        echo -e "\033[41;30m Wrong Answer \033[0m"
    fi
    L=$(($L+1))
    echo -e
done
