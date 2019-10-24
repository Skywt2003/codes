#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=998244353;

const int maxn=1e6+5;
const int N=1e6;

int T,n,m;
int fac[maxn],inv[maxn];

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt; b>>=1;
	}
	return ret;
}

void pre_build(){
	fac[0]=1;
	for (int i=1;i<=N;i++) fac[i]=fac[i-1]*i%tt;
	for (int i=0;i<=N;i++) inv[i]=qsm(fac[i],tt-2);
}

int C(int x,int y){
	// printf("C(%lld,%lld)\n",x,y);
	if (x<y) return 0;
	return fac[x]*inv[y]%tt*inv[x-y]%tt;
}

signed main(){
	pre_build();
	T=read();
	while (T--){
		n=read(),m=read();
		printf("%lld\n",C((n+m)/2,m));
	}
	return 0;
}