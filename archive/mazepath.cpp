#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const long long tt=1e9+7;
long long x;

// \frac 59 3 x^5 - \frac 11 3 x^3

inline long long qsm(long long a,long long b){
	long long ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt;b>>=1;
	}
	return ret;
}

int main(){
	scanf("%lld",&x);
	int inv=qsm(3,tt-2);
	long long ans=(qsm(x,5) *59%tt * inv%tt) - ((long long)qsm(x,3) * 11%tt * inv%tt);
	printf("%lld\n",(ans+tt)%tt);
	return 0;
}