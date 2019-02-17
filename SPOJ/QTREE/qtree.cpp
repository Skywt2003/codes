#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long
#define CLEAR(_) memset(_,0,sizeof(_))

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}

const int maxn=10005,maxe=2*maxn;
int T,n;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],rto[maxn],w[maxe];
int fa[maxn],son[maxn],deep[maxn],size[maxn],top[maxn],id[maxn],v[maxn];
int f[maxn][20];

#define ls (p<<1)
#define rs ((p<<1)+1)
#define mid (((tr-tl)>>1)+tl)

namespace SegmentTree{
	int tree[maxn*4];

	inline void clear(){
		memset(tree,0,sizeof(tree));
	}

	inline void update(int x,int tl,int tr,int p,int delta){
		// if (p!=0) cout<<p<<endl;
		if (x<tl || x>tr) return; else
		if (x==tl && tl==tr){
			tree[p]=delta;
			return;
		}
		if (x  <=mid) update(x,tl,mid  ,ls,delta);
		if (mid+1<=x) update(x,mid+1,tr,rs,delta);
		tree[p]=max(tree[ls],tree[rs]);
	}

	inline int query(int sl,int sr,int tl,int tr,int p){
		// if (p!=0) cout<<p<<endl;
		if (sl<=tl && tr<=sr) return tree[p];
		int ret=0;
		if (sl  <=mid) ret=max(ret,query(sl,sr,tl,mid  ,ls));
		if (mid+1<=sr) ret=max(ret,query(sl,sr,mid+1,tr,rs));
		return ret;
	}
}

inline void init(){
	SegmentTree::clear();
	tot=0;
	CLEAR(lnk),CLEAR(nxt),CLEAR(to),CLEAR(rto),CLEAR(w);
	CLEAR(fa),CLEAR(son),CLEAR(deep),CLEAR(size),CLEAR(top),CLEAR(id),CLEAR(v);
	CLEAR(f);
}

inline void add_edge(int x,int y,int z){
	tot++;to[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void build_tree(int x){
	size[x]=1;
	f[x][0]=fa[x];
	for (int i=1;i<=16;i++) f[x][i]=f[f[x][i-1]][i-1];
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		v[to[i]]=w[i];rto[(i+1)>>1]=to[i];
		deep[to[i]]=deep[x]+1;
		fa[to[i]]=x;
		build_tree(to[i]);
		size[x]+=size[to[i]];
		if (son[x]==0 || size[to[i]]>size[son[x]]) son[x]=to[i];
	}
}
inline void build_chain(int x){
	id[x]=++id[0];
	if (son[x]){
		top[son[x]]=top[x];
		build_chain(son[x]);
	}
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=son[x] && to[i]!=fa[x]){
		top[to[i]]=to[i];
		build_chain(to[i]);
	}
}

inline int get_lca(int x,int y){
	if (deep[x]<deep[y]) swap(x,y);
	for (int i=16;i>=0;i--) if (deep[f[x][i]]>=deep[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=16;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return fa[x];
}

signed main(){
	T=read();
	while (T--){
		n=read();init();
		for (int i=1;i<n;i++){
			int x=read(),y=read(),z=read();
			add_edge(x,y,z);add_edge(y,x,z);
		}
		deep[1]=1;top[1]=1;
		build_tree(1);
		build_chain(1);
		for (int x=2;x<=n;x++) SegmentTree::update(id[x],1,id[0],1,v[x]);

		char ch=getchar();while (ch!='Q' && ch!='C' && ch!='D') ch=getchar();
		for (;;){
			if (ch=='D') break; else
			if (ch=='Q'){
				int x=read(),y=read();
				int l=get_lca(x,y),ans=0;
				while (x!=l){
					if (son[fa[x]]==x){
						if (deep[top[x]]<deep[l]){
							ans=max(ans,SegmentTree::query(id[l]+1,id[x],1,id[0],1));
							x=l;break;
						} else {
							ans=max(ans,SegmentTree::query(id[top[x]]+1,id[x],1,id[0],1));
							x=top[x];
						}
					} else ans=max(ans,v[x]),x=fa[x];
				}
				while (y!=l){
					if (son[fa[y]]==y){
						if (deep[top[y]]<deep[l]){
							ans=max(ans,SegmentTree::query(id[l]+1,id[y],1,id[0],1));
							y=l;break;
						} else {
							ans=max(ans,SegmentTree::query(id[top[y]]+1,id[y],1,id[0],1));
							y=top[y];
						}
					} else ans=max(ans,v[y]),y=fa[y];
				}
				printf("%lld\n",ans);
			} else if (ch=='C'){
				int x=read(),delta=read();
				v[rto[x]]=delta;
				SegmentTree::update(id[rto[x]],1,id[0],1,delta);
			}
			ch=getchar();while (ch!='Q' && ch!='C' && ch!='D') ch=getchar();
		}
	}
	return 0;
}