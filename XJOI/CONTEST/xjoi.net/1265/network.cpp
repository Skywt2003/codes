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

int n;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int deg[maxn],f[maxn][22],deep[maxn];

int root=-1,leaves=0;
bool vis[maxn];

struct node{
	int x,y,w;
	bool operator <(node b)const{return w > b.w;}
	bool operator >(node b)const{return w < b.w;}
};
priority_queue<node> heap;

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_tree(int x){
	for (int i=1;i<22;i++) f[x][i]=f[f[x][i-1]][i-1];
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=f[x][0]){
		deep[to[i]]=deep[x]+1;
		f[to[i]][0]=x;
		build_tree(to[i]);
	}
}

int get_lca(int x,int y){
	if (deep[x]<deep[y]) swap(x,y);
	for (int i=21;i>=0;i--) if (deep[f[x][i]]>=deep[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=21;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

bool xAllOne=true;

namespace subtask2{
	signed main(){
		for (int i=2;i<n;i+=2) printf("%lld %lld\n",i,i+1);
		if ((n&1)==0) printf("%lld %lld\n",2,n);
		return 0;
	}
}

signed main(){
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y); add_edge(y,x);
		if (x!=1) xAllOne=false;
		deg[x]++; deg[y]++;
	}

	if (xAllOne) return subtask2::main();

	for (int i=1;i<=n;i++) if (deg[i]!=1) {if (root==-1) root=i;} else leaves++;
	deep[root]=1; build_tree(root);

	printf("%lld\n",(leaves+1)/2);
	
	for (int i=1;i<=n;i++) if (deg[i]==1)
		for (int j=i+1;j<=n;j++) if (deg[j]==1)
			heap.push((node){i,j,get_lca(i,j)});

	for (int i=1;i<=leaves/2;i++){
		node now=heap.top(); heap.pop();
		while (vis[now.x] || vis[now.y]) now=heap.top(),heap.pop();
		printf("%lld %lld\n",now.x,now.y); vis[now.x]=vis[now.y]=true;
	}

	for (int i=1;i<=n;i++) if (deg[i]==1 && vis[i]==false){
		for (int j=1;j<=n;j++) if (deg[j]==1 && vis[j]==true){
			printf("%lld %lld\n",i,j);
			break;
		}
		break;
	}

	return 0;
}