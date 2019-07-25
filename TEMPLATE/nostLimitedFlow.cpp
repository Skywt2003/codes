#include<bits/stdc++.h>
//#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=1<<30;
const int maxn=305,maxe=50405;

int n,m,ss,tt,ans=0,rst[maxe],low[maxe],high[maxe];
int tot=-1,lnk[maxn],nxt[maxe],to[maxe],w[maxe],cur[maxn];
int deep[maxn];
queue<int> que;

void addEdge(int x,int y,int z){
	tot++;to[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

int ind[maxn],outd[maxn];

bool BFS(){
	memset(deep,0,sizeof(deep));
	while (!que.empty()) que.pop();
	que.push(ss);deep[ss]=1;
	while (!que.empty()){
		int head=que.front();que.pop();
		for (int i=lnk[head];i!=-1;i=nxt[i]) if (w[i]>0 && deep[to[i]]==0) deep[to[i]]=deep[head]+1,que.push(to[i]);
	}
	return deep[tt];
}

int DFS(int x,int now){
	if (x==tt) return now;
	for (int i=cur[x];i!=-1;i=cur[x]=nxt[i]) if (deep[to[i]]==deep[x]+1 && w[i]>0){
		int nxtd=DFS(to[i],min(now,w[i]));
		if (nxtd>0){
			w[i]-=nxtd;
			w[i^1]+=nxtd;
			return nxtd;
		}
	}
	return 0;
}

int Dinic(){
	int ret=0;
	while (BFS()){
		for (int i=1;i<=n;i++) cur[i]=lnk[i];
		while (int now=DFS(ss,INF)) ret+=now;
	}
	return ret;
}

signed main(){
	memset(lnk,-1,sizeof(lnk));
	memset(nxt,-1,sizeof(nxt));
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();low[i]=read(),high[i]=read();
		outd[x]+=low[i],ind[y]+=low[i];
		addEdge(x,y,high[i]-low[i]);addEdge(y,x,0); rst[i]=tot;
	}
	
	ss=n+1;tt=n+2;
	for (int i=1;i<=n;i++){
		if (ind[i]-outd[i]<0) addEdge(i,tt,outd[i]-ind[i]),addEdge(tt,i,0);
		if (ind[i]-outd[i]>0) addEdge(ss,i,ind[i]-outd[i]),addEdge(i,ss,0);
	}
	n+=2;
	Dinic();
	for (int i=lnk[ss];i!=-1;i=nxt[i]) if (w[i]){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i=1;i<=m;i++) printf("%d\n",w[rst[i]]+low[i]);
	return 0;
}
