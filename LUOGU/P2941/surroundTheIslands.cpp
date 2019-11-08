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
const int maxn=506,maxe=1005;

int n;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int cost[maxn][maxn];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

int dfn[maxn],low[maxn];
bool vis[maxn];

stack<int> stk;
int cnt=0;
vector<int> inc[maxn];
int blt[maxn];

void tarjan(int x){
	dfn[x]=low[x]=++dfn[0]; vis[x]=true;
	stk.push(x);
	for (int i=lnk[x];i;i=nxt[i]) if (!dfn[to[i]]){
		tarjan(to[i]);
		low[x]=min(low[x],low[to[i]]);
	} else if (vis[to[i]]) low[x]=min(low[x],dfn[to[i]]);
	if (low[x] == dfn[x]){
		cnt++;
		for (;;){
			int now=stk.top(); stk.pop();
			blt[now]=cnt; inc[cnt].push_back(now);
			vis[now]=false;
			if (now==x) break;
		}
	}
}

int dist[maxn][maxn];
int ans=INF;

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cost[i][j]=read();

	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);

	for (int i=1;i<=cnt;i++)
		for (int j=i+1;j<=cnt;j++){
			int now=INF;
			for (int k=0;k<inc[i].size();k++)
				for (int t=0;t<inc[j].size();t++)
					now=min(now,cost[inc[i][k]][inc[j][t]]);
			dist[i][j]=dist[j][i]=now;
		}
	
	for (int i=1;i<=cnt;i++){
		int now=0;
		for (int j=1;j<=cnt;j++) if (i!=j) now+=dist[i][j];
		ans=min(ans,now);
	}
	
	printf("%lld\n",ans*2);
	return 0;
}