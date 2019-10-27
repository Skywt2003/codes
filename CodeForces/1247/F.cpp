#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;

int n,fa[maxn],deep[maxn];
int tot=0,lnk[maxn],nxt[maxn],to[maxn],son[maxn];

int opt[maxn],ans[maxn];

int heavy_son[maxn];

void add_edge(int x,int y){
	tot++; to[tot]=y; son[x]++;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

int cnt=0;

void DFS(int x){
	ans[++ans[0]]=x;
	for (int i=1;i<=cnt;i++) opt[++opt[0]]=x;
	cnt=0;
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=heavy_son[x]) DFS(to[i]);
	if (heavy_son[x]) DFS(heavy_son[x]);
	cnt++;
}

signed main(){
	n=read();

	fa[0]=-1; deep[0]=1;
	for (int i=1;i<n;i++) fa[i]=read(),add_edge(fa[i],i),deep[i]=deep[fa[i]]+1;

	int max_deep=0,k=-1;
	for (int i=0;i<n;i++) if (deep[i]>max_deep) max_deep=deep[i],k=i;
	while (k!=-1){
		if (fa[k]!=-1) heavy_son[fa[k]]=k;
		k=fa[k];
	}

	DFS(0);

	for (int i=1;i<=ans[0];i++) printf("%lld ",ans[i]); printf("\n");

	printf("%lld\n",opt[0]);
	for (int i=1;i<=opt[0];i++) printf("%lld ",opt[i]);
	printf("\n");
	return 0;
}