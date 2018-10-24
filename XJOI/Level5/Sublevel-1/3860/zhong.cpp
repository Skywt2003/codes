#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

#define int long long
using namespace std;

const int maxn=1e5+5;
int n,m,ans=0;
int a[maxn],b[maxn];
const int zero=maxn;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void generate_data(int n,int seed,int m){
	for (int i=1;i<=n;i++){
		a[i]=(seed / (1<<16)) % m;
		seed=(seed * 1103515245 + 12345) % (1<<31);
	}
}

namespace BIT{
	int tree[maxn*2];

	inline int lowbit(int x){
		return x&(-x);
	}

	inline void init(){
		memset(tree,0,sizeof(tree));
	}

	inline void update(int x,int delta){
		while (x<=zero+n) tree[x]+=delta,x+=lowbit(x);
	}

	inline int query(int x){
		int ret=0;
		while (x) ret+=tree[x],x-=lowbit(x);
		return ret;
	}
}

signed main(){
	n=read();int s=read();m=read();
	generate_data(n,s,m);
	int ans=0;
	for (int k=0;k<50;k++){
		BIT::init();
		for (int i=1;i<=n;i++) b[i]=b[i-1]+(a[i]==k);
		BIT::update(zero,1);
		for (int i=1;i<=n;i++){
			ans+=BIT::query(2*b[i]-i-1 +zero);
			BIT::update(2*b[i]-i+zero,1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}