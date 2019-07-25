#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=(int)1<<60;
const int mv[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
const int maxnn=25;
const int maxn=2005,maxe=500005;

int n,m,s,t;
int a[maxnn][maxnn],b[maxnn][maxnn],limit[maxnn][maxnn];

int tot=-1,lnk[maxn],nxt[maxe],to[maxe],w[maxe],c[maxe],cur[maxn];
int dist[maxn],pre[maxn];
bool vis[maxn];
queue<int> que;

int ans=0;

void addEdge(int x,int y,int z,int t){
	tot++;to[tot]=y;w[tot]=z;c[tot]=t;
	nxt[tot]=lnk[x];lnk[x]=tot;
} 

int numIn(int x,int y){return (x-1)*m+y;}
int numMid(int x,int y){return n*m+(x-1)*m+y;}
int numOut(int x,int y){return 2*n*m+(x-1)*m+y;}
bool check(int x,int y){
	if (x<1||y<1||x>n||y>m) return false;
	return true;
}

bool SPFA(){
	memset(dist,63,sizeof(dist));
	memset(vis,0,sizeof(vis));
	while (!que.empty()) que.pop();
	que.push(s); dist[s]=0; vis[s]=true;
	while (!que.empty()){
		int head=que.front();que.pop();vis[head]=false;
		for (int i=lnk[head];i!=-1;i=nxt[i]) if (w[i]>0 && dist[to[i]]>dist[head]+c[i]){
			dist[to[i]]=dist[head]+c[i]; pre[to[i]]=head;
			if (!vis[to[i]]) vis[to[i]]=true,que.push(to[i]);
		}
	}
	return dist[t]!=dist[0];
}

int DFS(int x,int now){
	if (x==t) return now;
	for (int i=cur[x];i!=-1;i=cur[x]=nxt[i]) if (w[i]>0 && pre[to[i]]==x){
		int nxtd=DFS(to[i],min(now,w[i]));
		if (nxtd>0){
			w[i]-=nxtd;
			w[i^1]+=nxtd;
			return nxtd;
		}
	}
	return 0;
}

void fakeDinic(){
	n=n*m*3+2;
	while (SPFA()){
		for (int i=1;i<=n;i++) cur[i]=lnk[i];
		while (int now=DFS(s,INF)){
			ans+=now*dist[t];
//			printf("%lld %lld\n",now,dist[t]);
		}
	}
	n=(n-2)/3/m;
}

signed main(){
	n=read();m=read();
	char ch=getchar();while (ch<'0'||ch>'9') ch=getchar();
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			a[i][j]=ch-'0';
			ch=getchar();while (ch<'0'||ch>'9') ch=getchar();
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			b[i][j]=ch-'0';
			ch=getchar();while (ch<'0'||ch>'9') ch=getchar();
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			limit[i][j]=ch-'0';
			if (i==n && j==m) continue;
			ch=getchar();while (ch<'0'||ch>'9') ch=getchar();
		}
	}

	memset(lnk,-1,sizeof(lnk));
	memset(nxt,-1,sizeof(nxt));
	s=n*m*3+1; t=n*m*3+2;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++){
		if (a[i][j]) addEdge(s,numMid(i,j),1,0),addEdge(numMid(i,j),s,0,0);
		if (b[i][j]) addEdge(numMid(i,j),t,1,0),addEdge(t,numMid(i,j),0,0);
		for (int k=0;k<8;k++) if (check(i+mv[k][0],j+mv[k][1])){
			addEdge(numOut(i,j),numIn(i+mv[k][0],j+mv[k][1]),INF,1);
			addEdge(numIn(i+mv[k][0],j+mv[k][1]),numOut(i,j),0,-1);
		}
        addEdge(numIn(i,j), numMid(i,j),(limit[i][j]+(!a[i][j]&& b[i][j]))/2,0);
		addEdge(numMid(i,j),numIn(i,j), 0,0);
        addEdge(numMid(i,j),numOut(i,j),(limit[i][j]+( a[i][j]&&!b[i][j]))/2,0);
		addEdge(numOut(i,j),numMid(i,j),0,0);
	}

	fakeDinic();
	printf("%lld\n",ans?ans:-1);
	return 0;
}
