#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005,maxe=1000005;
int n,m,q,INF;
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
int dst[maxn][maxn];
int a[maxn],d[maxn];

inline void add_edge(int x,int y){
	tot++;son[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

namespace Graph{
	queue<int> que;
	bool vis[maxn];

	inline void init(){
		while (!que.empty()) que.pop();
		memset(vis,0,sizeof(vis));
	}

	inline void BFS(int s){
		memset(dst[s],0x3f,sizeof(dst[s]));INF=dst[s][0];
		que.push(s);vis[s]=true;dst[s][s]=0;
		while (!que.empty()){
			int head=que.front();que.pop();
			for (int i=lnk[head];i;i=nxt[i]) if (!vis[son[i]]){
				dst[s][son[i]]=dst[s][head]+1;
				vis[son[i]]=true;que.push(son[i]);
			}
		}
	}
}

signed main(){
	n=read();m=read();q=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}
	
	for (int i=1;i<=n;i++) Graph::init(),Graph::BFS(i);

	bool vis[maxn];
	while (q--){
		int k=read();
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=k;i++) a[i]=read(),d[i]=read();
		for (int i=1;i<=k;i++){
			for (int j=1;j<=n;j++) if (dst[a[i]][j] <= d[i]) vis[j]=true;
		}
		int ans=0;
		for (int i=1;i<=n;i++) ans+=vis[i];
		printf("%lld\n",ans);
	}
	return 0;
}