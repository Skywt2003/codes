#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int tt=1000000007;
long long n;
long long qsm(long long a,long long b){
	long long w=a%tt,ret=1;
	while (b){
		if (b&1) ret=(ret*w)%tt;
		w=w*w%tt;
		b>>=1;
	}
	return ret;
}
int main(){
	scanf("%lld",&n);
	if (n==0){printf("1\n");return 0;}
	long long x=qsm(2,n-1);
	printf("%lld\n",(((1+x*2)%tt)*x)%tt);
	return 0;
}
