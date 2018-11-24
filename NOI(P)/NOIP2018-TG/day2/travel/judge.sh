#!/bin/bash

file="travel"
L=1
R=25
time_limit=1

if g++ $file.cpp -o $file; then
    echo -e "\033[32m Compiled successfully \033[0m"
    echo -e
else
    echo -e "\033[45;37m Compiled Error! \033[0m"
    exit 0
fi

while [ $L -le $R ]
do
    echo -e "\033[33m Running on test $L... \033[0m"
    # /usr/bin/time -f %U ./$file < $file$L.in > $file$L.out 2>tmp
    # tm=`cat tmp`
    # rm tmp
	echo -e -n "\033[33m Test $L... \033[0m"
    if ! timeout $time_limit ./$file < $file$L.in > $file$L.out; then
        echo -e "\033[43;30m Time Limit Exceed! \033[0m"
    else
        if diff $file$L.out $file$L.ans; then
            echo -e "\033[42;30m Accepted \033[0m"
            rm $file$L.out
        else
            echo -e "\033[41;30m Wrong Answer! \033[0m"
        fi
    fi
    L=$(($L+1))
    echo -e
done
