#!/bin/bash

g++ arry.cpp -o my -Wall -g
g++ spj.cpp -o spj -Wall -g
g++ make_data.cpp -o make_data -Wall -g

i=1

while true; do
	./make_data > data.in
	./my < data.in > my.out
	./spj > result.out

    echo -e  -n "\033[33m Example $i: \033[0m"
    if diff std.out result.out; then
        echo -e "\033[42;37m Accepted \033[0m \n"
    else
        echo -e "\033[41;37m Wrong Answer \033[0m \n"
        exit 0
    fi
    i=$(($i+1))
done