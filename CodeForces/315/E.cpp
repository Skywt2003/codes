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

const int maxn=1e6+5,tt=1000000007;
int n,mx,a[maxn],f[maxn];

namespace BIT{
	int a[maxn];

	int lowbit(int x) {return x&(-x);};

	void update(int x,int delta){
		while (x<=mx) a[x]=(a[x]+delta+tt)%tt,x+=lowbit(x);
	}
	int query(int x){
		int ret=0;
		while (x) ret=(ret+a[x])%tt,x-=lowbit(x);
		return ret;
	}
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),mx=max(mx,a[i]);
	for (int i=1;i<=n;i++){
		int x=BIT::query(a[i]);
		BIT::update(a[i],-f[a[i]]);
		f[a[i]]=(x*a[i]%tt+a[i])%tt;
		BIT::update(a[i],f[a[i]]);
	}
	printf("%lld\n",BIT::query(mx));
	return 0;
}