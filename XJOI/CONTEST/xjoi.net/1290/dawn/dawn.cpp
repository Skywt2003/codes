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
int deep[maxn],fa[maxn];

int fac[maxn],inv[maxn];

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
	memset(fa,0,sizeof(fa));
}

void build_tree(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		deep[to[i]]=deep[x]+1; fa[to[i]]=x;
		build_tree(to[i]);
	}
}

void build_size(int x,int from){
	siz[x]=1;
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=from){
		build_size(to[i],x);
		siz[x]+=siz[to[i]];
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

void prebuild(){
	const int N=100000;
	fac[0]=1;
	for (int i=1;i<=N;i++) fac[i]=fac[i-1]*i%tt;
	for (int i=0;i<=N;i++) inv[i]=qsm(i,tt-2);
}

int C(int x,int y){
	if (x<y) return 0;
	return fac[x]*inv[y]%tt*inv[x-y]%tt;
}

int make_k1(int x,int y){
	if (deep[x]<deep[y]) swap(x,y);
	int fx=x,fy=y,lst=0;
	while (deep[fx]>deep[fy]) lst=fx,fx=fa[fx];

	if (fx==fy) build_size(x,fa[x]),build_size(y,lst);
	else build_size(x,fa[x]),build_size(y,fa[y]);

	return siz[x]*siz[y]%tt;
}

int make_k2(int x,int y){
	if (deep[x]<deep[y]) swap(x,y);
	int fx=x,fy=y,lst=0;
	while (deep[fx]>deep[fy]) lst=fx,fx=fa[fx];

	int fr;
	if (fx==fy) build_size(x,fa[x]),build_size(y,lst),fr=lst;
	else build_size(x,fa[x]),build_size(y,fa[y]),fr=fa[y];

	int ret1=0,ret2=0;
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		ret1=(ret1+siz[to[i]])%tt;
		for (int j=nxt[i];j;j=nxt[j]) if (i!=j && to[j]!=fa[x])
			ret1=(ret1+siz[to[i]]*siz[to[j]]%tt)%tt;
	}

	for (int i=lnk[y];i;i=nxt[i]) if (to[i]!=fr){
		ret2=(ret2+siz[to[i]])%tt;
		for (int j=nxt[i];j;j=nxt[j]) if (i!=j && to[j]!=fr)
			ret2=(ret2+siz[to[i]]*siz[to[j]]%tt)%tt;
	}

	return (ret1*2%tt+1)*(ret2*2%tt+1)%tt;
}

signed main(){
	// prebuild();
	T=read();
	while (T--){
		init();
		n=read(); q=read();
		for (int i=1;i<n;i++){
			int x=read(),y=read();
			add_edge(x,y);add_edge(y,x);
		}
		deep[1]=1;build_tree(1);
		while (q--){
			int k=read(),x=read(),y=read();
			if (k>2) printf("0\n"); else
			printf("%lld\n",(k==1)?make_k1(x,y):make_k2(x,y));			
		}
	}
	return 0;
}