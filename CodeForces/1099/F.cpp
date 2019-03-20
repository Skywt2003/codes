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

const int maxn=1e5+5,maxe=2*maxn,maxt=1e6+10,allt=1e6+1;
const int INF=1e9+7;

int n,T;
int t[maxn],s[maxn];

int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];

int f[maxn];

namespace BIT_value{
	int tree[maxt*4];

	int lowbit(int x){
		return x&(-x);
	}

	void update(int x,int delta){
		while (x<=allt) tree[x]+=delta,x+=lowbit(x);
	}

	int query(int x){
		int ret=0;
		while (x) ret+=tree[x],x-=lowbit(x);
		return ret;
	}
}
namespace BIT_num{
	int tree[maxt*4];

	int lowbit(int x){
		return x&(-x);
	}

	void update(int x,int delta){
		while (x<=allt) tree[x]+=delta,x+=lowbit(x);
	}

	int query(int x){
		int ret=0;
		while (x) ret+=tree[x],x-=lowbit(x);
		return ret;
	}
}

void add_edge(int x,int y,int z){
	tot++;to[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

int get_num(int x){
	int ret=0;
	int L=1,R=allt,fin=0;
	while (L<=R){
		int mid=((R-L)>>1)+L;
		int sum=BIT_value::query(mid);
		if (sum<=x) fin=mid,L=mid+1; else R=mid-1;
	}
	int need=BIT_value::query(fin);
	ret=BIT_num::query(fin);
	if (fin+1<=allt) ret+=(x-need)/(fin+1);
	return ret;
}

void find_answer(int x,int fa,int spt){
	if (spt*2>T) {f[x]=0;return;}
	BIT_value::update(t[x],s[x]*t[x]);
	BIT_num::update(t[x],s[x]);
	f[x]=get_num(T-spt*2);
	int zmax=-INF,cmax=-INF;
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
		find_answer(to[i],x,spt+w[i]);
		if (f[to[i]]>zmax) cmax=zmax,zmax=f[to[i]]; else
		if (f[to[i]]>cmax) cmax=f[to[i]];
	}
	f[x]=max(f[x],((x==1)?zmax:cmax));
	BIT_value::update(t[x],-s[x]*t[x]);
	BIT_num::update(t[x],-s[x]);
}

signed main(){
	n=read();T=read();
	for (int i=1;i<=n;i++) s[i]=read();
	for (int i=1;i<=n;i++) t[i]=read();
	for (int i=2;i<=n;i++){
		int x=read(),y=read();
		add_edge(i,x,y); add_edge(x,i,y);
	}
	find_answer(1,-1,0);
	printf("%lld\n",f[1]);
	return 0;
}