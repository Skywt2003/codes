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

const int maxn=15,maxe=2005,maxs=4096+10;

int n,m,alls,ans=INF;

int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int f[maxs];

queue<int> que;
bool vis[maxn];
int dist[maxs][maxn];

void add_edge(int x,int y,int z){
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

signed main(){
	#ifndef ONLINE_JUDGE
		freopen("testdata.in","r",stdin);
	#endif

	n=read(); m=read(); alls=1ll<<n;
	for (int i=0;i<m;i++){
		int x=read()-1,y=read()-1,z=read();
		add_edge(x,y,z);add_edge(y,x,z);
	}

	for (int i=0;i<n;i++){
		memset(f,0x3f,sizeof(f));
		memset(dist,0x3f,sizeof(dist));
		f[1ll<<i]=0; dist[1ll<<i][i]=1;
		for (int j=0;j<alls;j++) if (f[j]!=INF){
			for (int k=0;k<n;k++) if ((j&(1ll<<k)) && dist[j][k]!=INF){
				for (int t=lnk[k];t;t=nxt[t]) if ((j&(1ll<<to[t]))==false){
					int nj=j|(1ll<<to[t]);
					if (f[j]+dist[j][k]*w[t] < f[nj]){
						f[nj]=f[j]+dist[j][k]*w[t];
						for (int ii=0;ii<n;ii++) dist[nj][ii]=dist[j][ii];
						dist[nj][to[t]]=dist[j][k]+1;
					}
				}
			}
		}
		ans=min(ans,f[alls-1]);
	}
	printf("%lld\n",ans);
	return 0;
}