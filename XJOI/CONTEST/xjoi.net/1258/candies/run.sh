#!/bin/bash

g++ make_data.cpp -o make_data -g -Wall
g++ candies.cpp -o my -g -Wall
g++ candies0.cpp -o std -g -Wall

i=1

while true; do
    ./make_data > data.in
    ./std < data.in > std.out
    ./my < data.in > my.out
    echo -e  -n "\033[33m Example $i: \033[0m"
    if diff std.out my.out; then
        echo -e "\033[42;37m Accepted \033[0m \n"
    else
        echo -e "\033[41;37m Wrong Answer \033[0m \n"
        exit 0
    fi
    i=$(($i+1))
done