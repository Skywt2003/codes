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

const int maxn=1e5+5,INF=1e9+5;

int n,k;
int a[maxn],sum[maxn];
int rat[maxn];
bool vis[maxn];

int lowbit(int x){
	return x&(-x);
}

namespace BIT{
	int tree[maxn*2];

	void update(int x,int delta){
		while (x<=n) tree[x]+=delta,x+=lowbit(x);
	}
	int query(int x){
		int ret=0;
		while (x) ret+=tree[x],x-=lowbit(x);
		return ret;
	}
}

namespace BIT2{
	int tree[maxn*2];

	void update(int x,int delta){
		while (x<=n) tree[x]+=delta,x+=lowbit(x);
	}
	int query(int x){
		int ret=0;
		while (x) ret+=tree[x],x-=lowbit(x);
		return ret;
	}
}

signed main(){
	n=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++){
		rat[i]=sum[i-1];
		sum[i]=sum[i-1]+a[i]*(i-1);
	}
	for (;;){
		int now=-1,mx=-INF;
		for (int i=1;i<=n;i++) if (vis[i]==false){
			int ii=i-BIT2::query(i);
			int rn=rat[i]-(ii-1)*(n-ii)*a[i]-BIT::query(i);
			if (rn<k && rn>mx){
				mx=rn;now=i;
			}
		}
		if (now==-1) break;
		vis[now]=true;printf("%lld\n",now);
		BIT::update(now,a[now]*(now-1));
		BIT2::update(now,1);
	}
	return 0;
}