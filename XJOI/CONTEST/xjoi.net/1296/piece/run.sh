#!/bin/bash

g++ make_data.cpp -o make_data
g++ piece.cpp -o my
g++ piece0.cpp -o std

i=1

while true; do
	./make_data > data.in
	./my < data.in > my.out
	./std < data.in > std.out
	
	echo -e  -n "\033[33m Example $i: \033[0m"
	if diff std.out my.out; then
		echo -e "\033[42;37m Accepted \033[0m \n"
	else
		echo -e "\033[41;37m Wrong Answer \033[0m \n"
		exit 0
	fi
	i=$(($i+1))
done
