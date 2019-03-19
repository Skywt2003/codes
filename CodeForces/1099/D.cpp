#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;

#define int long long
const int INF=1e9;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5,maxe=2e5+5;
int tot=0,lnk[maxn],nxt[maxe],son[maxe];

inline void add_edge(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

int n,fa[maxn],s[maxn],v[maxn];
int imp=false;

inline void DFS(int x,int sum){
	if (imp) return;
	if (s[x]==-1){
		if (lnk[x]==0) s[x]=sum; else {
			s[x]=INF;
			for (int i=lnk[x];i;i=nxt[i]) s[x]=min(s[x],s[son[i]]);
		}
	}
	v[x]=s[x]-sum;
	if (sum>s[x]){
		imp=true;
		return;
	}
	for (int i=lnk[x];i;i=nxt[i]) DFS(son[i],s[x]);
}

signed main(){
	n=read();
	for (int i=2;i<=n;i++) fa[i]=read(),add_edge(fa[i],i);
	for (int i=1;i<=n;i++) s[i]=read();
	DFS(1,0);
	int ans=0;
	for (int i=1;i<=n;i++) ans+=v[i];
	if (imp) printf("-1\n"); else printf("%lld\n",ans);
	return 0;
}