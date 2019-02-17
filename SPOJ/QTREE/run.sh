#!/bin/bash
g++ qtree.cpp -o qtree -g -Wall
g++ qtree0.cpp -o qtree0 -g -Wall
i=1
while true; do
    python3 make_data.py > data.in
    ./qtree0 < data.in > std.out
    ./qtree < data.in > my.out
    echo -e  -n "\033[33m Example $i... \033[0m"
    if diff std.out my.out; then
        echo -e "\033[32m PASSED \033[0m"
    else
        echo -e "\033[31m FAILED\033[0m"
        exit 0
    fi
    i=$(($i+1))
done
