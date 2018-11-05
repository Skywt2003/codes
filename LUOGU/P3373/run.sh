
g++ seg.cpp -o seg -Wall -g
g++ seg0.cpp -o seg0 -Wall -g
g++ make_data.cpp -o make_data -Wall -g

while true; do
	./make_data > data.in
	./seg < data.in > seg.out
	./seg0 < data.in > seg0.out
	if diff seg.out seg0.out; then
		echo "Accepted"
	else
		echo "Diffrent Answer! :("
		exit 0
	fi
done