#!/usr/bin/env python

from cyaron import * 

n = 200000
m = 200000

print(n)
print(m)

graph = tree = Graph.tree(n,weight_limit=(1,1e18))
print(graph)


for i in range(m):
	opt=randint(1,2)
	if opt == 1:
		print(opt,randint(1,n),randint(1,n),randint(1,1e18))
	else:
		print(opt,randint(1,n-1),randint(1,1e18))

