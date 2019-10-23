#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;

const int maxn=1e5+5,maxe=4e5+5;
const int maxk=25;
const int tt=998244353;

int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int dist[maxk][maxn];

struct node{
	int x,w;
	inline bool operator <(node b)const{return w>b.w;}
	inline bool operator >(node b)const{return w<b.w;}
};

priority_queue <node> heap;
bool vis[maxn];

void Dijkstra(int s,int k){
	memset(dist[k],63,sizeof(dist[k]));
	memset(vis,0,sizeof(vis));
	while (!heap.empty()) heap.pop();

	dist[k][s]=0.0;
	heap.push((node){s,dist[k][s]});
	while (!heap.empty()){
		node now=heap.top(); heap.pop();
		if (vis[now.x]) continue;
		vis[now.x]=true;
		for (int i=lnk[now.x];i;i=nxt[i]) if (dist[k][now.x]+w[i]<dist[k][to[i]]){
			dist[k][to[i]]=dist[k][now.x]+w[i];
			if (!vis[to[i]]) heap.push((node){to[i],dist[k][to[i]]});
		}
	}
}

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		b>>=1; w=w*w%tt;
	}
	return ret;
}

void add_edge(int x,int y,int z){
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

int n,m,k;
int b[maxk];

int mask[maxn];
int ans[1048576+5];
int init[1048576+5];

bool DFS(int s){
	if (ans[s]!=-1) return ans[s];
	bool ret=init[s];
	for (int i=0;i<k;i++)
		if (s&(1ll<<i)) ret|=DFS(s-(1ll<<i));
	ans[s]=ret;
	// printf("%lld ans= %lld\n",s,ans[s]);
	return ans[s];
}

signed main(){
	n=read(); m=read(); k=read();
	for (int i=0;i<k;i++) b[i]=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		add_edge(x,y,z); add_edge(y,x,z);
	}

	for (int i=0;i<k;i++) Dijkstra(b[i],i);

	int max_dist=0;
	for (int i=1;i<=n;i++){
		int now_min=INF;
		for (int j=0;j<k;j++) now_min=min(now_min,dist[j][i]);
		max_dist=max(max_dist,now_min);
	}

	memset(ans,-1,sizeof(ans));
	for (int i=1;i<=n;i++){
		for (int j=0;j<k;j++)
			if (dist[j][i] <= max_dist) mask[i]|=1ll<<j;
		init[mask[i]]=1;
	}

	DFS((1ll<<k)-1);

	int res=0;
	for (int i=0;i<(1ll<<k);i++) res=(res+(ans[i]<=0))%tt;

	printf("%lld\n",res*qsm((1ll<<k)%tt,tt-2)%tt);
	return 0;
}