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

int n,m,s,t,ss,tt,ans=0;
int tot=-1,lnk[maxn],nxt[maxe],to[maxe],w[maxe],cur[maxn];
int deep[maxn],dig[maxn];
queue<int> que;

void addEdge(int x,int y,int z){
	tot++;to[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}
void linkEdge(int x,int y,int z){
	addEdge(x,y,z);addEdge(y,x,0);
}

bool BFS(){
	memset(deep,0,sizeof(deep));
	while (!que.empty()) que.pop();
	que.push(ss);deep[ss]=1;
	while (!que.empty()){
		int head=que.front();que.pop();
		for (int i=lnk[head];i!=-1;i=nxt[i]) if (w[i]>0 && deep[to[i]]==0) deep[to[i]]=deep[head]+1,que.push(to[i]);
	}
//	printf("BFS ok\n");
	return deep[tt];
}

int DFS(int x,int now){
	if (x==tt) return now;
	int left=now;
	for (int i=cur[x];i!=-1 && left;i=cur[x]=nxt[i]) if (deep[to[i]]==deep[x]+1 && w[i]>0){
		int nxtd=DFS(to[i],min(left,w[i]));
		if (nxtd>0){
			left-=nxtd;
			w[i]-=nxtd;
			w[i^1]+=nxtd;
		}
	}
	if (left) deep[x]=-1;
	return now-left;
}

int Dinic(){
	n+=4;
	int ret=0;
	while (BFS()){
		for (int i=1;i<=n;i++) cur[i]=lnk[i];
		while (int now=DFS(ss,INF)) ret+=now;
	}
	n-=4;
	return ret;
}

signed main(){
	memset(lnk,-1,sizeof(lnk));
	memset(nxt,-1,sizeof(nxt));
	n=read();
	for (int i=1;i<=n;i++){
		int x=read();
		for (int j=1;j<=x;j++){
			int y=read();
			dig[i]--;dig[y]++;
			linkEdge(i,y,INF-1);
		}
	}
	s=n+1;t=n+2;ss=n+3;tt=n+4;
	
	for (int i=1;i<=n;i++){
		if (dig[i]>0) linkEdge(ss,i,dig[i]);
		if (dig[i]<0) linkEdge(i,tt,-dig[i]);
		linkEdge(s,i,INF),linkEdge(i,t,INF);
	}
	linkEdge(t,s,INF);
	Dinic();
	for (int i=lnk[ss];i!=-1;i=nxt[i]) w[i]=w[i^1]=0;
	for (int i=lnk[tt];i!=-1;i=nxt[i]) w[i]=w[i^1]=0;
	for (int i=lnk[t];i!=-1;i=nxt[i]) if (to[i]==s) ans+=w[i^1],w[i]=w[i^1]=0;
	linkEdge(ss,t,INF); linkEdge(s,tt,INF);
	ans-=Dinic();
	printf("%d\n",ans);
	return 0;
}
