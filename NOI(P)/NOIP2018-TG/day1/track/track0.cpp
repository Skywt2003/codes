// For 55 pts

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005,maxe=2*maxn;
int n,m,ans=0;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int fa[maxn],deep[maxn],dist[maxn],fa_edge_id[maxn],f[maxn][25];

int L=0,R=0;

inline void add_edge(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void build_tree(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa[x]) fa[son[i]]=x,deep[son[i]]=deep[x]+1,dist[son[i]]=dist[x]+w[i],fa_edge_id[son[i]]=i+1>>1,build_tree(son[i]);
}

inline void build_lca(){
	for (int i=1;i<=n;i++) f[i][0]=fa[i];
	for (int j=1;j<12;j++)
		for (int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
}

inline int get_lca(int x,int y){
	if (deep[x]>deep[y]) swap(x,y);
	for (int i=11;i>=0;i--) if (deep[x]<=deep[f[y][i]]) y=f[y][i];
	if (x==y) return x;
	for (int i=11;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return fa[x];
}

namespace UniSet{
	int fa[maxn*maxn],sum[maxn];
	
	inline void init(int n){
		for (int i=1;i<=n;i++) fa[i]=i,sum[i]=1;
	}
	
	inline int getfa(int x){
		if (fa[x]==x) return x;
		fa[x]=getfa(fa[x]);
		return fa[x];
	}
	
	inline void merge(int x,int y){
		x=getfa(x);y=getfa(y);
		if (x!=y) fa[x]=y,sum[y]+=sum[x],sum[x]=0;
	}
	
	inline int count_parts(int n){
		int ret=0;
		for (int i=1;i<=n;i++) if (sum[i]>1) ret++;
		return ret;
	}
}

inline void find_path(int x,int y,int now){
	if (x==y) return;
	cout<<fa_edge_id[x]<<" ";
	UniSet::merge(now,fa_edge_id[x]);
	if (fa[x]!=y) UniSet::merge(fa_edge_id[x],fa_edge_id[fa[x]]);
	find_path(fa[x],y,now);
}

inline bool check(int x){
	cout<<"Check "<<x<<": -------------------"<<endl;
	UniSet::init(n*n);
	int cnt=n-1;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			int lca=get_lca(i,j);
			if (dist[i]-dist[lca]+dist[j]-dist[lca] < x) continue;
			cout<<"Added path from "<<i<<" to "<<j<<", length = "<<dist[i]-dist[lca]+dist[j]-dist[lca]<<endl;
			cnt++;
			find_path(i,lca,cnt);
			find_path(j,lca,cnt);
			cout<<endl;
		}
	}
	if (UniSet::count_parts(cnt) >= m) cout<<"Oh yeah!!!"<<endl;
	cout<<UniSet::count_parts(cnt)<<endl;
	cout<<"Chech stops."<<endl<<endl;
	return UniSet::count_parts(cnt) >= m;
}

namespace Subtask1{
	
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add_edge(x,y,z);add_edge(y,x,z);R+=z;
	}
	if (m==1) return Subtask1::main();
	build_tree(1);
	build_lca();
	check(15);
	
	while (L<=R){
		int mid=((R-L)>>1)+L;
		if (check(mid)) ans=mid,L=mid+1; else R=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
