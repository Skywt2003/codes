#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1000005,N=1000000;
long long tt=1000003;
int T,n,m;
long long fac[maxn],inv[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return  ret*f;
}
inline long long qsm(long long a,int b){
	long long ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=(long long)w*w%tt;b>>=1;
	}
	return ret;
}
inline void BuildFactInverse(){
	fac[0]=1;
	for (int i=1;i<=N;i++) fac[i]=(long long)fac[i-1]*(long long)i%tt;
	inv[0]=1;
	for (int i=1;i<=N;i++) inv[i]=(long long)qsm(fac[i],tt-2);
}
inline long long C(int x,int y){
	return (long long)fac[x]*inv[x-y]%tt*inv[y]%tt;
}

int main(){
	T=read();
	BuildFactInverse();
	for (int t=1;t<=T;t++){
		n=read();m=read();
		printf("Case %d: %lld\n",t,(long long)C(n,m));
	}
	return 0;
}