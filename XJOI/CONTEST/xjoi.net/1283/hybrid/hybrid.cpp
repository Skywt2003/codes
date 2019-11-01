#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;

const int tt=998244353;

int n,m,k;
int fac[maxn],inv[maxn];

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt; b>>=1;
	}
	return ret;
}

void prebuild(){
	const int N=1000;
	fac[0]=1;
	for (int i=1;i<=N;i++) fac[i]=fac[i-1]*i%tt;
	for (int i=0;i<=N;i++) inv[i]=qsm(fac[i],tt-2);
}

int C(int x,int y){
	if (x<y) return 0;
	return fac[x]*inv[y]%tt*inv[x-y]%tt;
}

namespace subtask1{
	signed main(){
		int ans=0;
		for (int i=1;i<=m;i++) ans=(ans+C(k,i))%tt;
		printf("%lld\n",ans);
		return 0;
	}
};

signed main(){
	prebuild();
	n=read(); m=read(); k=read();
	if (n==1) return subtask1::main();
	else printf("0\n");
	return 0;
}