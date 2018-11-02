#!/bin/bash

g++ make_data.cpp -o make_data -g -Wall
g++ miku0.cpp -o miku0 -g -Wall
g++ miku.cpp -o miku -g -Wall

i=1
while true; do
    ./make_data > data.in
    ./miku < data.in > miku.out
    ./miku0 < data.in > miku0.out
    echo -e  -n "\033[33m Example $i... \033[0m"
    if diff miku.out miku0.out; then
        echo -e "\033[32m Accepted \033[0m"
    else
        echo -e "\033[31m Wrong Answer! \033[0m"
        exit 0
    fi
    i=$(($i+1))
done