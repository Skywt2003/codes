#!/bin/bash
g++ D.cpp -o D -g -Wall
g++ D0.cpp -o D0 -g -Wall
i=1
while true; do
    python3 make_data.py > data.in
    ./D0 < data.in > std.out
    ./D < data.in > my.out
    echo -e  -n "\033[33m Example $i... \033[0m"
    if diff std.out my.out; then
        echo -e "\033[32m PASSED \033[0m"
    else
        echo -e "\033[31m FAILED\033[0m"
        exit 0
    fi
    i=$(($i+1))
done