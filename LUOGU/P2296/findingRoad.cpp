#include<bits/stdc++.h>

// #define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=0x3f3f3f3f;
const int maxn=10005,maxe=200005;

int n,e,s,t;

int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int rtot=0,rlnk[maxn],rnxt[maxe],rto[maxe];

bool avl[maxn]; // Avalible nodes
bool cat[maxn]; // Can go to T

pair<int,int> edge[maxe];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

void add_redge(int x,int y){
	rtot++; rto[rtot]=y;
	rnxt[rtot]=rlnk[x]; rlnk[x]=rtot;
}

void clear_edges(){
	tot=0;
	memset(lnk,0,sizeof(lnk));
	memset(nxt,0,sizeof(nxt));
	memset(to,0,sizeof(to));
}

void rebuild_edges(){
	for (int i=1;i<=n;i++) if (cat[i]){
		avl[i]=true;
		for (int j=lnk[i];j;j=nxt[j]) avl[i]&=cat[to[j]];
		#ifdef EBUG
			if (avl[i]) printf("node %d avalible\n",i);
		#endif
	}

	clear_edges();

	for (int i=1;i<=e;i++) if (avl[edge[i].first] && avl[edge[i].second])
		add_edge(edge[i].first,edge[i].second);
}

queue<int> que;
int dist[maxn];
bool vis[maxn];

void build_cat(int s){
	while (!que.empty()) que.pop();

	que.push(s); cat[s]=true;
	while (!que.empty()){
		int head=que.front(); que.pop();
		for (int i=rlnk[head];i;i=rnxt[i]) if (!cat[rto[i]])
			cat[rto[i]]=true,que.push(rto[i]);
	}
}

void build_dist(int s){
	while (!que.empty()) que.pop();
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));

	que.push(s); vis[s]=true; dist[s]=0;
	while (!que.empty()){
		int head=que.front(); que.pop();
		for (int i=lnk[head];i;i=nxt[i]) if (!vis[to[i]])
			dist[to[i]]=dist[head]+1,que.push(to[i]),vis[to[i]]=true;
	}
}

signed main(){
	#ifndef ONLINE_JUDGE
		freopen("testdata.in","r",stdin);
	#endif

	n=read(); e=read();
	for (int i=1;i<=e;i++){
		edge[i].first=read(),edge[i].second=read();
		add_edge(edge[i].first,edge[i].second);
		add_redge(edge[i].second,edge[i].first);
	}
	s=read(),t=read();

	build_cat(t);

	rebuild_edges();

	build_dist(s);

	printf("%d\n",(dist[t]==INF)?-1:dist[t]);
	return 0;
}