#include<bits/stdc++.h>


namespace MyMath{
	inline int abs(int x){
		return x<0?-x:x;
	}

	inline int sqr(int x){
		return x*x;
	}

	inline int qsm(int a,int b,int tt){
		int ret=1,w=a;
		while (b){
			if (b&1) ret=ret*w%tt;
			w=w*w%tt;b>>=1;
		}
		return ret;
	}
}
