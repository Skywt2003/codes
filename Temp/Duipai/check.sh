#!/bin/bash
g++ my.cpp -o my

i=1
j=3
file="data"
while [ $i -le $j ]
do
    echo -e "\033[33m running on test $i... \033[0m"
    /usr/bin/time -f %U ./my < $file$i.in > my$i.out 2>tmp
    tm=`cat tmp`
    rm tmp
    if diff my.out $file$i.out; then
        echo -e -n "\033[33m Example $i... \033[0m"
        echo -e "\033[32m PASSED   Time: $tm s\033[0m"
        rm my$i.out
    else
        echo -e -n "\033[33m Example $i... \033[0m"
        echo -e "\033[31m FAILED\033[0m"
    fi
    i=$(($i+1))
    echo -e
done
