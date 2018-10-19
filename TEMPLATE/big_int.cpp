// 181019

#include<bits/stdc++.h>

const int maxlen=50;

struct bigint{
	int n,a[maxlen];

	bigint(){n=0;memset(a,0,sizeof(a));}

	bool operator ==(bigint b){
		if (n!=b.n) return false;
		for (int i=1;i<=n;i++) if (a[i]!=b.a[i]) return false;
		return true;
	}

	bigint operator =(int x){

	}
};