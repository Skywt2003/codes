#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=60005,maxe=500005;
const int INF=(int)1<<60;
int n,e,s,t;
int tot=-1,lnk[maxn],nxt[maxe],to[maxe],w[maxe],cur[maxn];
int deep[maxn];
int ans=0,flow=0;
queue<int> que;

void add_edge(int x,int y,int z){
	tot++;to[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

bool BFS(){
	memset(deep,0,sizeof(deep));
	while (!que.empty()) que.pop();
	que.push(s);deep[s]=1;
	while (!que.empty()){
		int head=que.front();que.pop();
		for (int i=lnk[head];i!=-1;i=nxt[i]) if (w[i]>0 && deep[to[i]]==0) deep[to[i]]=deep[head]+1,que.push(to[i]);
	}
	return deep[t];
}

int DFS(int x,int now){
	if (x==t) return now;
	for (int i=cur[x];i!=-1;i=cur[x]=nxt[i]) if (deep[to[i]]==deep[x]+1 && w[i]){
		int nxtd=DFS(to[i],min(now,w[i]));
		if (nxtd>0){
			w[i]-=nxtd;
			w[i^1]+=nxtd;
			return nxtd;
		}
	}
	return 0;
}

void Dinic(){
	while (BFS()){
		for (int i=1;i<=n;i++) cur[i]=lnk[i];
		while (int now=DFS(s,INF)) flow+=now;
	}
}

int p[maxn],c[maxn];

signed main(){
	n=read();e=read();
	for (int i=1;i<=n;i++) p[i]=read();
	
	memset(lnk,-1,sizeof(lnk));
	memset(nxt,-1,sizeof(nxt));
	for (int i=n+1;i<=n+e;i++){
		int x=read(),y=read(); c[i]=read(),ans+=c[i];
		add_edge(i,x,INF);add_edge(x,i,0);
		add_edge(i,y,INF);add_edge(y,i,0);
	}
	for (int i=n+1;i<=n+e;i++) add_edge(n+e+1,i,c[i]),add_edge(i,n+e+1,0);
	for (int i=1;i<=n;i++) add_edge(i,n+e+2,p[i]),add_edge(n+e+2,i,0);
	n+=e; s=++n; t=++n;
	
	Dinic();
	
	ans-=flow;
	printf("%lld\n",ans);
	return 0;
}
