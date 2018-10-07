/*
 * XJOI CONTEST 1013
 * T2 - tree
 * 181005 By SkyWT
 */

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3005,maxe=6005;
int n,p,q;
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
int ans=0;

vector < pair <int,int> > edges;

inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

namespace LCA{
	int f[maxn][13],deep[maxn];

	inline void build_father(int x){
		for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=f[x][0]){
			f[son[i]][0]=x;
			deep[son[i]]=deep[x]+1;
			build_father(son[i]);
		}
	}

	inline void build_lca(){
		for (int j=1;j<13;j++)
		for (int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	}

	inline int get_lca(int x,int y){
		if (deep[x]<deep[y]) swap(x,y);
		for (int i=12;i>=0;i--) if (deep[f[x][i]]>=deep[y]) x=f[x][i];
		if (x==y) return x;
		for (int i=12;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
		return f[x][0];
	}

	inline int get_distance(int x,int y,int l){
		if (l==-1) l=get_lca(x,y);
		return deep[x]-deep[l] + deep[y]-deep[l];
	}
}

namespace DP{
	int f[maxn],g[maxn];
	// f[i]: 以 i 点为 lca 并且长度为 q 的路径数量
	// g[i]: 经过 i 边并且长度为 q 的路径数量
	int deep[maxn],cnt[maxn],bck[maxn];
	bool vis[maxn];

	inline void build_sub_deep(int x){
		for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=f[x][0] && vis[son[i]]){
			deep[son[i]]=deep[x]+1;
			cnt[son[i]]++;
			build_sub_deep(son[i]);
		}
	}

	inline void make_dp(){
		memset_clear_tre(vis);
		for (int i=1;i<=n;i++){ // Build F[i]
			memset_clear_reg(deep);
			deep[i]=1;cnt[1]++;
			build_sub_deep(i);
			for (int j=0;j<=q;j++) f[i]+=cnt[j]*cnt[q-j];
		}
		for (int i=0;i<edges.size();i++){ // Build G[i]
			int x=edges[i].first;
			int y=edges[i].second;
			memset_clear_reg(deep);
			memset_clear_reg(cnt);

			deep[x]=deep[y]=1;
			vis[x]=false;build_sub_deep(y);vis[x]=true;
			for (int j=1;j<=n;j++) bck[j]=cnt[j];

			memset_clear_reg(cnt);
			vis[y]=false;build_sub_deep(x);vis[y]=true;
			for (int j=1;j<q;j++) f[i]+=cnt[j]*bck[q-j];
		}
	}
}

namespace DIF{
	int sum[2][maxn];

	inline void make_diff(int x,int y,int l,bool flag){
		if (flag){
			
		}
	}

	inline void add_up_answer(){

	}
}

signed main(){
	n=read():p=read();q=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		edges.push_back(make_pair(x,y));
		add(x,y);add(y,x);
	}
	LCA::deep[1]=1;
	LCA::build_father(1);

	DP::make_dp();

	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (i!=j){
			int l=LCA::get_lca(i,j);
			int d=LCA::get_distance(i,j,l);
			if (d==p) DIF::make_diff(i,j,l,0); else
			if (d==p) DIF::make_diff(i,j,l,1); else continue;
		}

	DIF::add_up_answer();
	printf("%lld\n",ans);
	return 0;
}