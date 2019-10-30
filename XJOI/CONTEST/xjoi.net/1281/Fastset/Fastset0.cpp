#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3005;

int n;
int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];
int dist[maxn];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_dist(int x,int fa){
	for (int i=lnk[x];i;i=nxt[i])
		if (to[i]!=fa) dist[to[i]]=dist[x]+1,build_dist(to[i],x);
}

int pos[maxn];
int ans=0;

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif

	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y); add_edge(y,x);
	}
	for (int i=1;i<=n;i++) pos[i]=i;

	for (int i=1;i<=n;i++){
		int l=read(),r=read(),p=read();
		memset(dist,0,sizeof(dist));
		build_dist(p,-1);
		for (int j=l;j<=r;j++) ans+=dist[pos[j]],pos[j]=p;
	}
	printf("%lld\n",ans);
	return 0;
}