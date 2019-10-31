#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=998244353;

const int maxn=1e5+5,N=1e5;

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt; b>>=1;
	}
	return ret;
}

int fac[maxn],inv[maxn];

void prebuild(){
	fac[0]=1;
	for (int i=1;i<=N;i++) fac[i]=fac[i-1]*i%tt;
	for (int i=0;i<=N;i++) inv[i]=qsm(fac[i],tt-2);
}

int T;
int opt,n,l,r,k;

int get_answer(int n,int k){
	int ret=1,now=n;
	for (int i=1;i<=k;i++) ret=(ret+(now*inv[i])%tt)%tt,now=now*(n-i)%tt;
	return ret;
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	prebuild();
	T=read();
	while (T--){
		opt=read();
		if (opt==1){
			n=read(),k=read();
			printf("%lld\n",get_answer(n,k));
		} else {
			l=read(),r=read(),k=read();
			printf("%lld\n",(get_answer(r+1,k+1)-get_answer(l,k+1)+tt)%tt);
		}
	}
	return 0;
}