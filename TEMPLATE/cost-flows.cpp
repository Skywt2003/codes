#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=5005,maxe=100005;
int INF;
int n,e,s,t;
int tot=-1,lnk[maxn],nxt[maxe],to[maxe],w[maxe],c[maxe],cur[maxn];
int dist[maxn],pre[maxn];
bool vis[maxn];
int ans1=0,ans2=0;
queue<int> que;

void add_edge(int x,int y,int z,int t){
	tot++;to[tot]=y;w[tot]=z;c[tot]=t;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

bool SPFA(){
	memset(pre,0,sizeof(pre));
	memset(dist,63,sizeof(dist));INF=dist[0];
	memset(vis,0,sizeof(vis));
	while (!que.empty()) que.pop();
	que.push(s); vis[s]=true; dist[s]=0;
	while (!que.empty()){
		int head=que.front();que.pop();vis[head]=false;
		for (int i=lnk[head];i!=-1;i=nxt[i]) if (w[i]>0 && dist[to[i]]>dist[head]+c[i]){
			dist[to[i]]=dist[head]+c[i];
			pre[to[i]]=head;
			if (vis[to[i]]==false){
				que.push(to[i]);
				vis[to[i]]=true;
			}
		}
	}
	return (dist[t]!=INF);
}

int DFS(int x,int now,int from){
	if (x==t) return now;
	for (int i=cur[x];i!=-1;i=cur[x]=nxt[i]) if (w[i]>0 && pre[to[i]]==x && to[i]!=from){
		int nxtd=DFS(to[i],min(now,w[i]),x);
		if (nxtd>0){
			w[i]-=nxtd;
			w[i^1]+=nxtd;
			return nxtd;
		}
	}
	return 0;
}

void Dinic(){
	while (SPFA()){
		for (int i=1;i<=n;i++) cur[i]=lnk[i];
		while (int now=DFS(s,INF,-1)) ans1+=now,ans2+=now*dist[t];
	}
}

signed main(){
//	freopen("testdata.in","r",stdin);
	memset(lnk,-1,sizeof(lnk));
	memset(nxt,-1,sizeof(nxt));
	n=read();e=read();s=read();t=read();
	for (int i=1;i<=e;i++){
		int x=read(),y=read(),z=read(),t=read();
		add_edge(x,y,z,t);add_edge(y,x,0,-t);
	}
	
	Dinic();
	
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}
