#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>

using namespace std;
#define int long long
#define sqr(_) ((_)*(_))

const int tt=998244353;
const int maxn=1005,maxe=2005;
int n,a[maxn],d[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],p[maxn];
int f[maxn],sum[maxn];
int g[maxn],h[maxn];
int ans=0;
int fa[maxn][25],deep[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add(int x,int y,int z){
	tot++;son[tot]=y;p[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline int lowbit(int x){
	return x&(-x);
}

namespace Tree{
	inline void _build_tree(int x){
		for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa[x][0]){
			fa[son[i]][0]=x;
			deep[son[i]]=deep[x]+1;
			_build_tree(son[i]);
		}
	}

	inline void build_tree(){
		deep[1]=1;
		_build_tree(1);
	}

	inline void _build_f(int x){

	}

	inline void build_f(){
		
	}
}

namespace LCA{
	inline void build_lca(){
		for (int j=1;j<25;j++)
			for (int i=1;i<=n;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
	}

	inline int get_grandfa(int x,int y){ // 返回 x 的 y 级祖先
		int ret=x;
		while (y){
			int delta=lowbit(y);
			if (fa[x][delta]==0) return 1;
			x=fa[x][delta];y-=delta;
		}
		return ret;
	}

	inline int get_lca(int x,int y){
		if (deep[x]<deep[y]) swap(x,y);
		for (int i=24;i>=0;i--) if (deep[fa[x][i]]>=deep[y]) x=fa[x][i];
		if (x==y) return x;
		for (int i=24;i>=0;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
		return fa[x][0];
	}
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),d[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	Tree::build_tree();
	return 0;
}