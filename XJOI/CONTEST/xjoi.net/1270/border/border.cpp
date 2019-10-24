#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=5e5+5;
const int tt=1e9+7;

int n,q;
int a[maxn];
int sum[maxn];
int ans[maxn];

int qsm(int a,int b){
	if (b<0) return 0;
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		b>>=1; w=w*w%tt;
	}
	return ret;
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read(); q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int tmp=1;
	for (int i=1;i<=n;i++) sum[i]=(sum[i-1]+a[i])%tt,ans[i]=(ans[i-1]+a[i]*tmp%tt)%tt,tmp=tmp*2%tt;
	
	while (q--){
		int x=read(),y=read();
		printf("%lld\n",(ans[y]-ans[x-1]+tt)%tt * qsm(qsm(2,x-1),tt-2)%tt);
	}

	return 0;
}