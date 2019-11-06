#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e6+5,maxe=2e6+5,maxm=1e6+5;

int n,m;

int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int deep[maxn],f[maxn][22];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

void build_tree(int x){
	for (int i=1;i<22;i++) f[x][i]=f[f[x][i-1]][i-1];
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=f[x][0]){
		f[to[i]][0]=x; deep[to[i]]=deep[x]+1;
		build_tree(to[i]);
	}
}

int get_lca(int x,int y){
	if (deep[x]<deep[y]) swap(x,y);
	for (int i=21;i>=0;i--) if (deep[f[x][i]] >= deep[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=21;i>=0;i--) if (f[x][i] != f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int get_dist(int x,int y){
	int lca=get_lca(x,y);
	return deep[x]-deep[lca]+deep[y]-deep[lca];
}

bool is_subtask3=true;
bool is_subtask5=true;

struct query{
	int x,y,d;
};
query q[maxm];

namespace subtask3{
	signed main(){
		#ifdef DEBUG
			printf("subtask3::main() | start\n");
		#endif
		puts("1");
		return 0;
	}
};

namespace subtask5{
	int sum[maxn],ans=-1;

	void find_answer(int x,int now){
		if (ans!=-1) return;
		if (now==m){ans=x;return;}
		for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=f[x][0]) find_answer(to[i],now+sum[to[i]]);
	}

	signed main(){
		#ifdef DEBUG
			printf("subtask5::main() | start\n");
		#endif
		for (int i=1;i<=m;i++){
			int lca=get_lca(q[i].x,q[i].y);
			sum[lca]++;
			if (lca!=q[i].x) for (int j=lnk[q[i].x];j;j=nxt[j]) if (to[j]!=f[q[i].x][0]) sum[to[j]]--;
			if (lca!=q[i].y) for (int j=lnk[q[i].y];j;j=nxt[j]) if (to[j]!=f[q[i].y][0]) sum[to[j]]--;
			if (lca==q[i].x && lca==q[i].y) for (int j=lnk[q[i].y];j;j=nxt[j]) if (to[j]!=f[q[i].y][0]) sum[to[j]]--;
		}
		
		find_answer(1,sum[1]);
		if (ans==-1) printf("NO\n"); else printf("%lld\n",ans);
		return 0;
	}
};

bool now_vis[maxn];
int cnt[maxn];

void make_now_tag(int x,int y){
	if (deep[x] < deep[y]) swap(x,y);
	while (deep[x]>deep[y]) now_vis[x]=true,x=f[x][0];
	while (x!=y) now_vis[x]=now_vis[y]=true,x=f[x][0],y=f[y][0];
	now_vis[x]=true;
}

void exDFS(int x,int lft){
	now_vis[x]=true;
	if (lft==0) return;
	for (int i=lnk[x];i;i=nxt[i]) if (!now_vis[to[i]]) exDFS(to[i],lft-1);
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read(); m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y); add_edge(y,x);
	}

	deep[1]=1;
	build_tree(1);
	
	for (int i=1;i<=m;i++){
		q[i].x=read(),q[i].y=read(),q[i].d=read();
		if (q[i].d != 2e6) is_subtask3=false;
		if (is_subtask5){
			int dist=get_dist(q[i].x,q[i].y);
			if (q[i].d != dist) is_subtask5=false;
		}
	}
	
	if (is_subtask3) return subtask3::main();
	if (is_subtask5) return subtask5::main();
	
	#ifdef DEBUG
		printf("main() | Other subtask\n");
	#endif
	
	for (int i=1;i<=m;i++){
		int dist=get_dist(q[i].x,q[i].y);
		int ext=(q[i].d-dist)/2;
		
		for (int j=1;j<=n;j++) now_vis[j]=false;
		make_now_tag(q[i].x,q[i].y);
		
		int xx=q[i].x,yy=q[i].y;
		if (deep[xx] < deep[yy]) swap(xx,yy);
		while (deep[xx] > deep[yy]) exDFS(xx,ext),xx=f[xx][0];
		while (xx!=yy) exDFS(xx,ext),exDFS(yy,ext),xx=f[xx][0],yy=f[yy][0];
		exDFS(xx,ext);
		
		for (int j=1;j<=n;j++) cnt[j]+=now_vis[j];
	}
	
	for (int i=1;i<=n;i++) if (cnt[i]==m){
		printf("%lld\n",i);
		return 0;
	}
	printf("NO\n");
	return 0;
}
