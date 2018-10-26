// 181026

#include<bits/stdc++.h>
using namespace std;

struct bitset{
	static const int maxn=30,maxm=30;
	int set[maxn];

	inline void clear(){
		memset(set,0,sizeof(set));
	}

	inline bool operator [](int index)const{
		index--;
		return (set[index/maxm]>>index%maxm)&1;
	}

	inline void set_value(int index,int value){
		index--;
		if (value) set[index/maxm]|=1<<index%maxm; else set[index/maxm]&=~(1<<index%maxm);
	}

	inline void merge(bitset b){
		for (int i=0;i<maxn;i++) set[i]|=b.set[i];
	}

	inline int count(){
		int ret=0;
		for (int i=0;i<maxn;i++) ret+=__builtin_popcount(set[i]);
		return ret;
	}
};