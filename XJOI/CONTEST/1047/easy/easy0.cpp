#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define int long long

using namespace std;

const int maxn=5005,maxe=2*maxn;

int n;
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
int f[maxn][26],deep[maxn];
int p[maxn],ans=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add_edge(int x,int y){
	tot++;son[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void build_tree(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=f[x][0]){
		f[son[i]][0]=x;deep[son[i]]=deep[x]+1;
		build_tree(son[i]);
	}
}

inline void build_lca(){
	for (int j=1;j<26;j++){
		for (int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
	}
}

inline int get_lca(int x,int y){
	if (deep[x]>deep[y]) swap(x,y);
	for (int i=25;i>=0;i--) if (deep[f[y][i]] >= deep[x]) y=f[y][i];
	if (x==y) return x;
	for (int i=25;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

signed main(){
	freopen("easy.in","r",stdin);
	freopen("easy0.out","w",stdout);
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}
	deep[1]=1;build_tree(1);
	build_lca();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++){
		int now=p[i];
		for (int j=i;j<=n;j++){
			now=get_lca(now,p[j]);
			ans+=deep[now];
		}
	}
	printf("%lld\n",ans);
	return 0;
}