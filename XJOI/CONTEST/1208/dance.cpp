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
const int maxnn=55;
const int maxn=305,maxe=100005;

int n,k,ans=-1;

int s,t;
int tot=-1,lnk[maxn],nxt[maxe],to[maxe],w[maxe],cur[maxn];
int deep[maxn];
queue<int> que;

void clearEdges(){
	tot=-1;
	memset(lnk,-1,sizeof(lnk));
	memset(nxt,-1,sizeof(nxt));
}
void addEdge(int x,int y,int z){
	tot++;to[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

int like[maxnn][maxnn];

bool BFS(){
	memset(deep,0,sizeof(deep)); while (!que.empty()) que.pop();
	deep[s]=1; que.push(s);
	while (!que.empty()){
		int head=que.front();que.pop();
		for (int i=lnk[head];i!=-1;i=nxt[i]) if (w[i]>0 && deep[to[i]]==0) deep[to[i]]=deep[head]+1,que.push(to[i]);
	}
	return deep[t];
}

int DFS(int x,int now){
	if (x==t) return now;
	for (int i=cur[x];i!=-1;i=cur[x]=nxt[i]) if (w[i]>0 && deep[to[i]]==deep[x]+1){
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
	n=n*4+2;
	int ret=0;
	while (BFS()){
		for (int i=1;i<=n;i++) cur[i]=lnk[i];
		while (int now=DFS(s,INF)) ret+=now;
	}
	n=(n-2)/4;
	return ret;
}

bool check(int a){ // 1~n: Boys like; n+1~2n: Girls like; 2n+1~3n: Boys dislike; 3n+1~4n: Girls dislike.
	clearEdges();
	s=4*n+1,t=4*n+2;
	for (int i=1;i<=n;i++) addEdge(s,i,a),addEdge(i,s,0);
	for (int i=n+1;i<=2*n;i++) addEdge(i,t,a),addEdge(t,i,0);
	for (int i=1;i<=n;i++) addEdge(i,2*n+i,k),addEdge(2*n+i,i,0),addEdge(3*n+i,n+i,k),addEdge(n+i,3*n+i,0);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		if (like[i][j]) addEdge(i,n+j,1),addEdge(n+j,i,0); else addEdge(2*n+i,3*n+j,1),addEdge(3*n+j,2*n+i,0);
	return Dinic()==a*n;
}

signed main(){
	n=read();k=read();
	char ch=getchar();while (ch==' '||ch==10||ch==13) ch=getchar();
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			like[i][j]=ch=='Y';
			if (i==n && j==n) continue;
			ch=getchar();while (ch==' '||ch==10||ch==13) ch=getchar();
		}
	}
	
	int L=0,R=INF;
	while (L<=R){
		int mid=((R-L)>>1)+L;
		if (check(mid)) ans=mid,L=mid+1; else R=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}
