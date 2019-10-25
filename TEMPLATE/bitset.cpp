#include<bits/stdc++.h>
using namespace std;

class bitset{
	static const int maxn=30,maxm=30;
	int set[maxn];

	void clear(){
		memset(set,0,sizeof(set));
	}

	bool operator [](int index)const{
		index--;
		return (set[index/maxm]>>index%maxm)&1;
	}

	void set_value(int index,int value){
		index--;
		if (value) set[index/maxm]|=1<<index%maxm; else set[index/maxm]&=~(1<<index%maxm);
	}

	void merge(bitset b){
		for (int i=0;i<maxn;i++) set[i]|=b.set[i];
	}

	int count(){
		int ret=0;
		for (int i=0;i<maxn;i++) ret+=__builtin_popcount(set[i]);
		// if use `long long`, use: __builtin_popcountll()
		return ret;
	}
};