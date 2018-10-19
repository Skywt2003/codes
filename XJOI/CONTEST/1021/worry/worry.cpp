#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

const int maxn=100005,maxe=2*maxn;
int n,m;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];

namespace Tree{
	int deep[maxn],fa[maxn];

	inline void make_tree(int x){
		for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa[x]){
			fa[son[i]]=x;
			deep[son[i]]=deep[x]+1;
			make_tree(x);
		}
	}
}

namespace UniSet{
	int fa[maxn];

	inline void init(int n){
		for (int i=1;i<=n;i++) fa[i]=i;
	}

	inline int getfa(int x){
		if (fa[x]==x) return x;
		fa[x]=getfa(fa[x]);
		return fa[x];
	}

	inline void merge(int x,int y){
		x=getfa(x),y=getfa(y);
		if (x==y) return;
		if (Tree::deep[x]<Tree::deep[y]) fa[y]=x; else fa[x]=y;
	}
}

struct edge{
	int x,y,w;
};
vector<edge> edges;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

signed main(){
	n=read();m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y,0);add(y,x,0);
	}
	Tree::make_tree(1);
	UniSet::init(n);
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		edges.push_back((edge){x,y,z});
	}
	
}