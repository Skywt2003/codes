cp ../wyz/std.cpp std.cpp
g++ std.cpp -o std -O2
for ((i=1;i<=20;++i))
do
	./std <$i.in >$i.ans
done
