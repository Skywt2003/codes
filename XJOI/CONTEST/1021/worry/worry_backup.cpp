#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define int long long
using namespace std;

const int maxn=50005,maxe=100005;
const int INF=(int)1<<60;
int n,m;
int tot=-1,lnk[maxn],son[maxe],nxt[maxe];
int cnt[maxn];
bool can_use[maxe];

struct edge{
	int x,y,z;
};
vector<edge> e;
vector<pair<int,int> > tree_edges;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void init(){
	memset(lnk,255,sizeof(lnk));
	memset(nxt,255,sizeof(nxt));
}

inline void add(int x,int y){
	tot++;son[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void DFS(int x,int fa,int flag){
	cnt[x]=flag;
	for (int i=lnk[x];i!=-1;i=nxt[i]) if (son[i]!=fa && can_use[i]) DFS(son[i],x,flag);
}

signed main(){
	init();
	n=read();m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
		tree_edges.push_back(make_pair(x,y));
	}
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		e.push_back((edge){x,y,z});
	}
	memset(can_use,1,sizeof(can_use));
	for (int i=1;i<n;i++){
		can_use[(i-1)*2]=can_use[((i-1)*2)^1]=false;
		DFS(tree_edges[i-1].first,-1,0);
		DFS(tree_edges[i-1].second,-1,1);
		int ans=INF;
		for (int j=0;j<m;j++) if (cnt[e[j].x]!=cnt[e[j].y]) ans=min(ans,e[j].z);
		printf("%lld\n",ans==INF?-1:ans);
		can_use[(i-1)*2]=can_use[((i-1)*2)^1]=true;
	}
	return 0;
}