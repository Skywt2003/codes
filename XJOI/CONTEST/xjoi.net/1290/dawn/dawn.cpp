#include<bits/stdc++.h>

#define int long long

const int INF=0x3f3f3f3f3f3f3f3f;
const int NEG_INF=0x8080808080808080;

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005,maxe=200005;
const int tt=998244353;

int T;
int n,q;

int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int siz[maxn];
int deep[maxn],f[maxn][25],w[maxn][25];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

void init(){
	tot=0;
	memset(lnk,0,sizeof(lnk));
	memset(nxt,0,sizeof(nxt));
	memset(to,0,sizeof(to));
	memset(deep,0,sizeof(deep));
	memset(f,0,sizeof(f));
	memset(w,0,sizeof(w));
	memset(siz,0,sizeof(siz));
}

void build_tree(int x){
	siz[x]=1;
	for (int i=1;i<25;i++) f[x][i]=f[f[x][i-1]][i-1],w[x][i]=w[f[x][i-1]][i-1];

	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=f[x][0]){
		deep[to[i]]=deep[x]+1;
		f[to[i]][0]=x; w[to[i]][0]=to[i];
		build_tree(to[i]);
		siz[x]+=siz[to[i]];
	}
}

pair<int,int> get_lca(int x,int y){
	pair<int,int> ret=make_pair(0,0);
	if (deep[x]<deep[y]) swap(x,y);
	for (int i=24;i>=0;i--) if (deep[f[x][i]] >= deep[y]) ret.second=w[x][i],x=f[x][i];
	if (x==y) {ret.first=x;return ret;}
	for (int i=24;i>=0;i--) if (f[x][i] != f[y][i]) x=f[x][i],y=f[y][i];
	return make_pair(f[x][0],-1);
}

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		b>>=1; w=w*w%tt;
	}
	return ret;
}

int get_answer(int x,int y,int k){
	if (deep[x]<deep[y]) swap(x,y);
	pair<int,int> ll=get_lca(x,y);
	if (ll.second == -1) ll.second=f[y][0];

	int ret1=qsm(siz[x],k);
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=f[x][0]) ret1=(ret1-qsm(siz[to[i]],k)+tt)%tt;

	int ret2=qsm(((ll.second==f[y][0])?(siz[y]):(n-siz[ll.second])),k);
	for (int i=lnk[y];i;i=nxt[i]) if (to[i]!=ll.second && to[i]!=f[y][0]) ret2=(ret2-qsm(siz[to[i]],k)+tt)%tt;
	if (ll.second != f[y][0]) ret2=(ret2-qsm(n-siz[y],k)+tt)%tt;

	return ret1*ret2%tt;
}

signed main(){
	T=read();
	while (T--){
		init();
		n=read(); q=read();
		for (int i=1;i<n;i++){
			int x=read(),y=read();
			add_edge(x,y);add_edge(y,x);
		}
		deep[1]=1; build_tree(1);
		while (q--){
			int k=read(),x=read(),y=read();
			printf("%lld\n",get_answer(x,y,k));
		}
	}
	return 0;
}