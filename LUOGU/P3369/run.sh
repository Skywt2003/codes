#!/bin/bash
g++ make_data.cpp -o make_data -g -Wall
g++ treap0.cpp -o std -g -Wall
g++ treap.cpp -o my -g -Wall
i=1
while true; do
    ./make_data > data.in
    ./std < data.in > std.out
    ./my < data.in > my.out
    echo -e  -n "\033[33m Example $i... \033[0m"
    if diff std.out my.out; then
        echo -e "\033[32m PASSED \033[0m"
    else
        echo -e "\033[31m FAILED\033[0m"
        exit 0
    fi
    i=$(($i+1))
done
