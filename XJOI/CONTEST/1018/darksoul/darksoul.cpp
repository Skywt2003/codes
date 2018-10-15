#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define int long long

const int maxn=1000005,maxe=2000005;
int n,ans=0;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int INF;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add(int x,int y,int z){
	tot++;son[tot]=y,w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

namespace Dijkstra{
	int dst[maxn];
	bool vis[maxn];
	void init(){
		memset(vis,0,sizeof(vis));
		memset(dst,0x3f,sizeof(dst));
		INF=dst[0];
	}
	void make_dist(int s){
		dst[s]=0;
		for (int i=lnk[s];i;i=nxt[i]) dst[son[i]]=min(dst[son[i]],dst[s]+w[i]);
		vis[s]=true;
		for (int i=2;i<=n;i++){
			int MIN=INF,k=-1;
			for (int j=1;j<=n;j++) if (vis[j]==false && dst[j]<MIN) MIN=dst[j],k=j;
			if (k==-1) printf("ERROR: No shortest path.\n");
			vis[k]=true;
			for (int j=lnk[k];j;j=nxt[j]) dst[son[j]]=min(dst[son[j]],dst[k]+w[j]);
		}
	}
	int get_max(){
		int ret=0;
		for (int i=1;i<=n;i++) ret=max(ret,dst[i]);
		return ret;
	}
}

signed main(){
	freopen("darksoul.in","r",stdin);
	freopen("darksoul.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	for (int i=1;i<=n;i++){
		Dijkstra::init();
		Dijkstra::make_dist(i);
		ans=max(ans,Dijkstra::get_max());
	}
	printf("%lld\n",ans+1);
	return 0;
}
