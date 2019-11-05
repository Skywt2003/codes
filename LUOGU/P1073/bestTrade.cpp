#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005,maxe=200005;

int n,m;
int a[maxn];

int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int rtot=0,rlnk[maxn],rnxt[maxe],rto[maxe];

int dist_min[maxn]; // dist_min[x]: minimal number from s to x
int ans=0;

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void add_redge(int x,int y){
	rtot++; rto[rtot]=y;
	rnxt[rtot]=rlnk[x]; rlnk[x]=tot;
}

bool avl[maxn];

bool vis[maxn];
queue<int> que;

void SPFA(int s){
	while (!que.empty()) que.pop();
	memset(vis,0,sizeof(vis));
	memset(dist_min,0x3f,sizeof(dist_min));

	que.push(s); vis[s]=true;
	while (!que.empty()){
		int head=que.front(); que.pop(); vis[head]=false; 
		for (int i=lnk[head];i;i=nxt[i])
			if (min(dist_min[head],a[to[i]]) < dist_min[to[i]]){
				dist_min[to[i]]=min(dist_min[head],a[to[i]]);
				if (!vis[to[i]]) vis[to[i]]=true,que.push(to[i]);
			}
	}
}

void rDFS(int x){
	if (avl[x]) return;
	avl[x]=true;
	for (int i=rlnk[x];i;i=rnxt[i]) if (!avl[rto[i]]) rDFS(rto[i]);
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif

	n=read(); m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),type=read();
		add_edge(x,y); add_redge(y,x);
		if (type==2) add_edge(y,x),add_redge(x,y);
	}

	rDFS(n);
	SPFA(1);

	for (int i=1;i<=n;i++) if (avl[i]) ans=max(ans,a[i]-dist_min[i]);

	printf("%lld\n",ans);
	return 0;
}
