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
int fa_edge[maxn],ans[maxe];

namespace Tree{
	int deep[maxn],fa[maxn];
	int f[maxn][27];

	inline void make_tree(int x){
		for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa[x]){
			fa[son[i]]=x;fa_edge[son[i]]=(i+1)/2;
			deep[son[i]]=deep[x]+1;
			make_tree(son[i]);
		}
	}

	inline void build_lca(){
		for (int i=1;i<=n;i++) f[i][0]=fa[i];
		for (int j=1;j<=26;j++)
			for (int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
	}

	inline int get_lca(int x,int y){
		if (deep[x]<deep[y]) swap(x,y);
		for (int i=26;i>=0;i--) if (deep[f[x][i]]>=deep[y]) x=f[x][i];
		if (x==y) return x;
		for (int i=26;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
		return fa[x];
	}

	inline void writelook(){
		printf("Write Look: ================\n");
		printf("ID:    ");for (int i=1;i<=n;i++) printf("%3lld ",i);printf("\n");
		printf("DEEP[]:");for (int i=1;i<=n;i++) printf("%3lld ",deep[i]);printf("\n");
		printf("FA[]:  ");for (int i=1;i<=n;i++) printf("%3lld ",fa[i]);printf("\n");
		printf("END ==========================");
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
		if (Tree::deep[x] < Tree::deep[y]) fa[y]=x; else fa[x]=y;
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

inline bool cmp(edge aa,edge bb){
	return aa.w<bb.w;
}

signed main(){
	n=read();m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y,0);add(y,x,0);
	}
	Tree::deep[1]=1;
	Tree::make_tree(1);
	Tree::build_lca();
	UniSet::init(n);

	edges.clear();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		edges.push_back((edge){x,y,z});
	}
	sort(edges.begin(),edges.end(),cmp);
	memset(ans,255,sizeof(ans));

	for (int i=0;i<edges.size();i++){
		int x=edges[i].x,y=edges[i].y;
		int f=Tree::get_lca(x,y);
		// printf("X=%lld  Y=%lld  F=%lld\n",x,y,f);
		for (;;){
			x=UniSet::getfa(x);
			if (Tree::deep[x]<=Tree::deep[f]) break;
			ans[fa_edge[x]]=edges[i].w;
			UniSet::merge(x,Tree::fa[x]);
			x=Tree::fa[x];
		}
		for (;;){
			y=UniSet::getfa(y);
			if (Tree::deep[y]<=Tree::deep[f]) break;
			ans[fa_edge[y]]=edges[i].w;
			UniSet::merge(y,Tree::fa[y]);
			y=Tree::fa[y];
		}
	}
	for (int i=1;i<n;i++) printf("%lld\n",ans[i]);
	return 0;
}