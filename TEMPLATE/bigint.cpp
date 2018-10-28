// 181019

#include<bits/stdc++.h>

const int maxlen=50;
using namespace std;

struct bigint{
	int len,a[maxlen];

	bigint(){len=0;memset(a,0,sizeof(a));}

	inline void init(){
		len=0;memset(a,0,sizeof(a));
	}

	inline bool operator ==(bigint b){
		if (len!=b.len) return false;
		for (int i=1;i<=len;i++) if (a[i]!=b.a[i]) return false;
		return true;
	}

	inline bigint operator =(int x){
		bigint ret;
		while (x) ret.a[++ret.len]=x%10,x/=10;
		return ret;
	}

	inline bigint operator +(bigint b){
		bigint c;
		c.len=max(len,b.len);
		for (int i=1;i<=c.len;i++){
			c.a[i]+=a[i]+b.a[i];
			c.a[i+1]+=c.a[i]/10;
			c.a[i]%=10;
		}
		while (c.a[c.len+1]) c.len++;
		return c;
	}

	inline bigint operator -(bigint b){
		
	}
};