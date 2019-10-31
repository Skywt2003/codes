#include<bits/stdc++.h>

#define int long long

using namespace std;

const int INF=0x3f3f3f3f3f3f3f3f;
const int NEG_INF=0x8080808080808080;

#define clear(_) memset(_,0,sizeof(_))

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005,maxe=200005,maxk=60;

int T;
int n,e,k,tt;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int rtot=0,rlnk[maxn],rnxt[maxe],rto[maxe],rw[maxe];
int f[maxn][maxk],dist[maxn];

void add_edge(int x,int y,int z){
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void add_redge(int x,int y,int z){
	rtot++; rto[rtot]=y; rw[rtot]=z;
	rnxt[rtot]=rlnk[x]; rlnk[x]=rtot;
}

queue<int> que;
bool vis[maxn];

void reverseSPFA(){
	while (!que.empty()) que.pop();
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));

	vis[n]=true; que.push(n); dist[n]=0;
	while (!que.empty()){
		int head=que.front(); que.pop(); vis[head]=false;
		for (int i=rlnk[head];i;i=rnxt[i]) if (dist[head]+rw[i] < dist[rto[i]]){
			dist[rto[i]]=dist[head]+rw[i];
			if (!vis[rto[i]]) vis[rto[i]]=true,que.push(rto[i]);
		}
	}
}

bool ind[maxn][maxk];

int DFS(int x,int y){
	if (ind[x][y]) return -1;
	if (f[x][y]) return f[x][y];
	ind[x][y]=true; f[x][y]=(x==n);

	for (int i=lnk[x];i;i=nxt[i]) if (y-(dist[to[i]]+w[i]-dist[x]) >= 0){
		int now=DFS(to[i],y-(dist[to[i]]+w[i]-dist[x]));
		if (now==-1) return f[x][y]=-1;
		f[x][y]=(f[x][y]+now)%tt;
	}
	ind[x][y]=false;
	return f[x][y];
}

void init(){
	tot=rtot=0;
	clear(lnk);clear(nxt),clear(to);clear(w);
	clear(rlnk);clear(rnxt);clear(rto);clear(rw);
	clear(f); clear(ind);
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	T=read();
	while (T--){
		init();
		n=read(); e=read(); k=read(); tt=read();
		for (int i=1;i<=e;i++){
			int x=read(),y=read(),z=read();
			add_edge(x,y,z); add_redge(y,x,z);
		}
		reverseSPFA();
		printf("%lld\n",DFS(1,k));
	}
	return 0;
}