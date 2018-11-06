#!/bin/bash

g++ queries.cpp -o queries -g -Wall
g++ queries0.cpp -o queries0 -g -Wall
g++ make_data.cpp -o make_data

i=1

while true; do
	./make_data > data.in
	./queries < data.in > my.out
	./queries0 < data.in > std.out
	echo -e  -n "\033[33m Example $i... \033[0m"
	if diff my.out std.out; then
		echo -e "\033[32m Accepted \033[0m"
	else
		echo -e "\033[31m Different Answer! \033[0m"
		exit 0
	fi
	i=$(($i+1))
done