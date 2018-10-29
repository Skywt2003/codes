#!/bin/bash
g++ math.cpp -o math
g++ math0.cpp -o math0
g++ make_data.cpp -o make_data
i=1

while true; do
	./make_data > data.in
	./math < data.in > math.out
	./math0 < data.in > math0.out
    echo -e -n "\033[33m Example $i... \033[0m"
    if diff math.out math0.out; then
        echo -e "\033[32m Accepted \033[0m"
    else
        echo -e "\033[31m Wrong Answer \033[0m"
        exit 0
    fi
    i=$(($i+1))
done