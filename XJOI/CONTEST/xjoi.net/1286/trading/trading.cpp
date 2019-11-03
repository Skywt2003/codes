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

const int maxn=5005,maxe=10005;

int n,m;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int siz[maxn];
int f[maxn][maxn];

void add_edge(int x,int y,int z){
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

void DFS(int x,int fa){
	siz[x]=1;
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
		DFS(to[i],x);
		for (int ii=siz[x];ii>=0;ii--)
			for (int jj=siz[to[i]];jj>=0;jj--) if (m-jj>=0 && siz[to[i]]-jj>=0 && n-m-siz[to[i]]+jj>=0)
				f[x][ii+jj]=max(f[x][ii+jj],f[x][ii]+f[to[i]][jj] + w[i]*jj*(m-jj) + w[i]*(siz[to[i]]-jj)*(n-m-siz[to[i]]+jj));
		siz[x]+=siz[to[i]];
	}
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read(); m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add_edge(x,y,z); add_edge(y,x,z);
	}
	
	DFS(1,-1);
	printf("%lld\n",f[1][m]);

	return 0;
}