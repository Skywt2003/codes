#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int NEG_INF=0x8080808080808080;

const int maxn=1e5+5;

int n;

int tot=0,lnk[maxn],nxt[2*maxn],to[2*maxn];
int dist[maxn],nds[maxn];

int ans=INF;

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_tree(int x,int fa){
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
		dist[to[i]]=dist[x]+1;
		build_tree(to[i],x);
	}
}

void build_nds(int x,int fa){
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
		nds[to[i]]=nds[x]+1;
		build_nds(to[i],x);
	}
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}

	build_tree(1,-1);

	for (int i=2;i<=n;i++){
		nds[i]=0; int now=0;
		build_nds(i,-1);
		for (int j=1;j<=n;j++) now+=min(dist[j],nds[j]+1);
		ans=min(ans,now);
	}

	printf("%lld\n",ans);
	return 0;
}