#!/bin/bash

g++ t2.cpp -o t2
g++ std.cpp -o std
g++ gen.cpp -o gen

i=1

while true; do
	./gen > data.in
	./t2 < data.in > my.out
	./std < data.in > std.out
	if diff my.out std.out; then
		echo -e "Test data $i: Accepted"
	else
		echo -e "Test data $i: Faild!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
		exit 0
	fi
	i=$(($i+1))
done
