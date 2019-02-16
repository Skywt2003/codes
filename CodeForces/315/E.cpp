#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5,tt=1000000007;
int n,a[maxn],f[maxn];

namespace BIT{
	int a[maxn];

	int lowbit(int x) {return x&(-x);};

	void update(int x,int delta){
		while (x<=n) a[x]=(a[x]+delta)%tt,x+=lowbit(x);
	}
	int query(int x){
		int ret=0;
		while (x) ret=(ret+a[x])%tt,x-=lowbit(x);
		return ret;
	}
}


signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read()%tt;
	f[1]=a[1];
	BIT::update(a[1],f[1]);
	for (int i=2;i<=n;i++){
		f[i]=(BIT::query(a[i])*a[i]%tt+a[i])%tt;
		BIT::update(a[i],f[i]);
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans=(ans+f[i])%tt;
	printf("%lld\n",ans);
	return 0;
}