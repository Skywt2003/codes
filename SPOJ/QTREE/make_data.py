#!/usr/bin/env python

from cyaron import * # 引入CYaRon的库

print(1)

n = 7 # 点数

print(n)

graph = tree = Graph.tree(n,weight_limit=(5,300)) # 生成一棵n个节点的随机树

print(graph) # 自动写入到输入文件里，默认以一行一组u v w的形式输出

for i in range(6):
	print("QUERY ",randint(1,n),randint(1,n));

print("DONE")