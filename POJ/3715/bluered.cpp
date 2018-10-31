#pragma GCC optmize(2)

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=205,maxm=40005;

int T,n,m,a[maxn],p[maxn];
int tot=0,lnk[maxn],nxt[maxm],son[maxm];
vector<int> v1,v2;

namespace Graph{
	bool vis[maxn];
	int con_x[maxn],con_y[maxn];

	inline void add_edge(int x,int y){
		tot++;son[tot]=y;
		nxt[tot]=lnk[x];lnk[x]=tot;
	}

	inline void init(){
		tot=0;
		memset(lnk,0,sizeof(lnk));
		memset(nxt,0,sizeof(nxt));
		memset(son,-1,sizeof(son));
	}

	inline bool DFS(int x){
		for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]){
			int t=son[i];vis[t]=true;
			if ((con_y[t]==-1) || (DFS(t))){
				con_x[x]=t;
				con_y[t]=x;
				return true;
			}
		}
		return false;
	}

	inline int max_match(){
		memset(con_x,-1,sizeof(con_x));
		memset(con_y,-1,sizeof(con_y));
		int ret=0;
		for (int i=0;i<v1.size();i++) memset(vis,0,sizeof(vis)),ret+=DFS(v1[i]);
		return ret;
	}
};

vector<pair<int,int> > edges;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	T=read();
	while (T--){
		v1.clear();v2.clear();
		edges.clear();
		Graph::init();
		n=read();m=read();
		for (int i=0;i<n;i++){
			a[i]=read();
			if (a[i]) v2.push_back(i); else v1.push_back(i);
		}
		for (int i=0;i<m;i++){
			int x=read(),y=read();
			edges.push_back(make_pair(x,y));
			if (a[x]==a[y]) continue;
			Graph::add_edge(x,y);
			Graph::add_edge(y,x);
		}
		int ans=Graph::max_match();
		printf("%lld ",ans);
		int cnt=0;
		for (int i=0;i<n && cnt<ans;i++){
			Graph::init();
			for (int j=0;j<edges.size();j++) if (edges[j].first!=i && edges[j].second!=i) Graph::add_edge(edges[j].first,edges[j].second),Graph::add_edge(edges[j].second,edges[i].first);
			if (Graph::max_match()!=ans) printf("%lld ",i),cnt++;
		}
		printf("\n");
	}
	return 0;
}