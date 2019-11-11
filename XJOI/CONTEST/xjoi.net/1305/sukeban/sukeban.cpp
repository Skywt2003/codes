#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt; b>>=1;
	}
	return ret;
}

const int maxn=1005,maxe=3005;

int T;
int n,m,k;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int pos[maxn][maxn];

struct bang{
	int x,a,b;
};
bang a[maxn];

void init(){
	tot=0;
	memset(lnk,0,sizeof(lnk));
	memset(nxt,0,sizeof(nxt));
	memset(to,0,sizeof(to));
	memset(pos,0,sizeof(pos));
}

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

queue<int> que;
int dist[maxn][maxn];
bool vis[maxn];

void get_dist(int s){
	memset(dist[s],0x3f,sizeof(dist[s]));
	memset(vis,0,sizeof(vis));
	while (!que.empty()) que.pop();
	
	que.push(s); dist[s][s]=0,vis[s]=true;
	while (!que.empty()){
		int head=que.front(); que.pop();
		for (int i=lnk[head];i;i=nxt[i]) if (!vis[to[i]]){
			dist[s][to[i]]=dist[s][head]+1;
			vis[to[i]]=true,que.push(to[i]);
		}
	}
}

void build_dist(int bid,int x,int y,int p,int step,int lim){
	pos[bid][x]=p;
	
	if (step==lim) return;
	int sum=0,minnum=INF;
	for (int i=lnk[x];i;i=nxt[i]) if (!vis[to[i]]) minnum=min(minnum,dist[to[i]][y]);
	for (int i=lnk[x];i;i=nxt[i]) if (!vis[to[i]] && dist[to[i]][y]==minnum) sum++;
	for (int i=lnk[x];i;i=nxt[i]) if (!vis[to[i]] && dist[to[i]][y]==minnum) {
		vis[to[i]]=true;
		build_dist(bid,to[i],y,p*qsm(sum,tt-2)%tt,step+1,lim);
		vis[to[i]]=false;
	}
}

signed main(){
	freopen("sukeban.in","r",stdin);
	freopen("sukeban.out","w",stdout);
	T=read();
	while (T--){
		init();
		
		n=read(); m=read(); k=read();
		for (int i=1;i<=m;i++){
			int x=read(),y=read();
			add_edge(x,y); add_edge(y,x);
		}

		for (int i=1;i<=n;i++) get_dist(i);
		
		for (int i=1;i<=k;i++){
			a[i].x=read(),a[i].a=read(),a[i].b=read();
			memset(vis,0,sizeof(vis));
			build_dist(i,a[i].a,a[i].b,1,0,dist[a[i].a][a[i].b]);
		}
		
		for (int i=1;i<=n;i++){
			int nowans=0; bool aws=false;
			for (int ii=1;ii<=k;ii++)
				for (int jj=ii+1;jj<=k;jj++) if (a[ii].x!=a[jj].x)
					if (pos[ii][i]*pos[jj][i]%tt==1) aws=true;
					else nowans=(nowans + pos[ii][i]*pos[jj][i]%tt)%tt;
			if (aws) printf("%lld\n",1ll); else printf("%lld\n",nowans);
		}
	}
	return 0;
}
