#pragma GCC optimize(2)

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=200005,maxe=2*maxn;
const int MAX=1e18;

#define ls (p<<1)
#define rs ((p<<1)+1)
#define mid (((tr-tl)>>1)+tl)

bool check_mul(int x,int y){
	if (log10(x-1)+1+log10(y-1)+1 > 18) return false;
	if (x*y>MAX || x*y<0) return false;
	return true;
}

namespace SegmentTree{
	int tree[maxn*4];

	void update(int x,int tl,int tr,int p,int delta){
		if (tl>x || tr<x) return;
		if (tl==tr && tl==x) {tree[p]=delta;return;}
		if (x<=mid  ) update(x,tl,mid,ls,delta); else
		if (mid+1<=x) update(x,mid+1,tr,rs,delta);
		if (tree[ls]>MAX || tree[ls]<0 || tree[rs]>MAX || tree[rs]<0 || check_mul(tree[ls],tree[rs])==false) tree[p]=-1; else
		tree[p]=tree[ls]*tree[rs];
	}

	int query(int sl,int sr,int tl,int tr,int p){
		if (sl<=tl && tr<=sr) return tree[p];
		int ret=1,lf=1,rf=1;
		if (sl<=mid  ) lf=query(sl,sr,tl,mid,ls);
		if (mid+1<=sr) rf=query(sl,sr,mid+1,tr,rs);
		if (lf<0 || lf>MAX || rf<0 || rf>MAX || check_mul(lf,rf)==false) return -1;
		ret=lf*rf;
		if (ret<0 || ret>MAX) return -1;
		return ret;
	}
}

int n,m;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int fa[maxn],son[maxn],sze[maxn],top[maxn],v[maxn],deep[maxn],id[maxn],rto[maxn];
int f[maxn][22];

void add_edge(int x,int y,int z){
	tot++;to[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

void make_tree(int x){
	sze[x]=1;
	f[x][0]=fa[x];
	for (int i=1;i<=21;i++) f[x][i]=f[f[x][i-1]][i-1];
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		fa[to[i]]=x;deep[to[i]]=deep[x]+1;
		v[to[i]]=w[i];rto[(i+1)>>1]=to[i];
		make_tree(to[i]);
		sze[x]+=sze[to[i]];
		if (son[x]==0 || sze[to[i]]>sze[son[x]]) son[x]=to[i];
	}
}

void make_chain(int x){
	id[x]=++id[0];
	if (son[x]){
		top[son[x]]=top[x];
		make_chain(son[x]);
	}
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x] && to[i]!=son[x]){
		top[to[i]]=to[i];
		make_chain(to[i]);
	}
}

int get_lca(int x,int y){
	if (deep[x]>deep[y]) swap(x,y);
	for (int i=21;i>=0;i--) if (deep[f[y][i]]>=deep[x]) y=f[y][i];
	if (x==y) return x;
	for (int i=21;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return fa[x];
}

signed main(){
	n=read();m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add_edge(x,y,z);add_edge(y,x,z);
	}
	deep[1]=1;top[1]=1;
	make_tree(1);make_chain(1);
	for (int i=2;i<=n;i++) SegmentTree::update(id[i],1,id[0],1,v[i]);

	while (m--){
		int opt=read();
		if (opt==1){
			int x=read(),y=read(),num=read();
			int l=get_lca(x,y),now=1;
			while (x!=l){
				int tmp=-1;
				if (top[x]!=x){
					if (deep[top[x]]<deep[l]){
						tmp=SegmentTree::query(id[l]+1,id[x],1,id[0],1);
						x=l;
					} else {
						tmp=SegmentTree::query(id[top[x]]+1,id[x],1,id[0],1);
						x=top[x];
					}
				} else tmp=v[x],x=fa[x];
				if (tmp<0 || tmp>num || check_mul(tmp,now)==false){now=-1;break;}
				now=now*tmp;
				if (now<0 || now>num) break;
			}
			if (now<0 || now>num){printf("0\n");continue;}
			while (y!=l){
				int tmp=-1;
				if (top[y]!=y){
					if (deep[top[y]]<deep[l]){
						tmp=SegmentTree::query(id[l]+1,id[y],1,id[0],1);
						y=l;
					} else {
						tmp=SegmentTree::query(id[top[y]]+1,id[y],1,id[0],1);
						y=top[y];
					}
				} else tmp=v[y],y=fa[y];
				if (tmp<0 || tmp>num || check_mul(tmp,now)==false){now=-1;break;}
				now=now*tmp;
				if (now<0 || now>num) break;
			}
			if (now<0 || now>num){printf("0\n");continue;}
			printf("%lld\n",num/now);
		} else {
			int x=read(),delta=read();
			v[rto[x]]=delta;
			SegmentTree::update(id[rto[x]],1,id[0],1,delta);
		}
	}
	return 0;
}