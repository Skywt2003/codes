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

const int maxn=30005,maxe=2*maxn,INF=1e7+5;
int T,n;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int fa[maxn],son[maxn],deep[maxn],size[maxn],top[maxn],id[maxn],w[maxn];
int f[maxn][20];

#define ls (p<<1)
#define rs ((p<<1)+1)
#define mid (((tr-tl)>>1)+tl)

namespace SegmentTree{
	int mx[maxn*4],sm[maxn*4];

	inline void update(int x,int tl,int tr,int p,int delta){
		if (x<tl || x>tr) return; else
		if (x==tl && tl==tr){
			mx[p]=sm[p]=delta;
			return;
		}
		if (x  <=mid) update(x,tl,mid  ,ls,delta);
		if (mid+1<=x) update(x,mid+1,tr,rs,delta);
		mx[p]=max(mx[ls],mx[rs]);
		sm[p]=sm[ls]+sm[rs];
	}

	inline int query_max(int sl,int sr,int tl,int tr,int p){
		if (sl<=tl && tr<=sr) return mx[p];
		int ret=-INF;
		if (sl  <=mid) ret=max(ret,query_max(sl,sr,tl,mid  ,ls));
		if (mid+1<=sr) ret=max(ret,query_max(sl,sr,mid+1,tr,rs));
		return ret;
	}

	inline int query_sum(int sl,int sr,int tl,int tr,int p){
		if (sl<=tl && tr<=sr) return sm[p];
		int ret=0;
		if (sl  <=mid) ret+=query_sum(sl,sr,tl,mid  ,ls);
		if (mid+1<=sr) ret+=query_sum(sl,sr,mid+1,tr,rs);
		return ret;
	}
}

inline void add_edge(int x,int y){
	tot++;to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void build_tree(int x){
	size[x]=1;
	f[x][0]=fa[x];
	for (int i=1;i<=18;i++) f[x][i]=f[f[x][i-1]][i-1];
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
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
	for (int i=18;i>=0;i--) if (deep[f[x][i]]>=deep[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=18;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return fa[x];
}

signed main(){
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}
	deep[1]=1;top[1]=1;
	build_tree(1);
	build_chain(1);
	for (int i=1;i<=n;i++) w[i]=read(),SegmentTree::update(id[i],1,id[0],1,w[i]);

	int m=read();
	char ch=getchar();while (ch!='Q' && ch!='C') ch=getchar();
	for (int k=1;k<=m;k++){
		if (ch=='Q'){
			char ch2=getchar();
			if (ch2=='M'){
				int x=read(),y=read();
				int l=get_lca(x,y),ans=-INF;
				while (x!=l){
					if (son[fa[x]]==x){
						if (deep[top[x]]<deep[l]){
							ans=max(ans,SegmentTree::query_max(id[l]+1,id[x],1,id[0],1));
							x=l;break;
						} else {
							ans=max(ans,SegmentTree::query_max(id[top[x]]+1,id[x],1,id[0],1));
							x=top[x];
						}
					} else ans=max(ans,w[x]),x=fa[x];
				}
				while (y!=l){
					if (son[fa[y]]==y){
						if (deep[top[y]]<deep[l]){
							ans=max(ans,SegmentTree::query_max(id[l]+1,id[y],1,id[0],1));
							y=l;break;
						} else {
							ans=max(ans,SegmentTree::query_max(id[top[y]]+1,id[y],1,id[0],1));
							y=top[y];
						}
					} else ans=max(ans,w[y]),y=fa[y];
				}
				printf("%lld\n",max(ans,w[l]));
			} else {
				int x=read(),y=read();
				int l=get_lca(x,y),ans=0;
				while (x!=l){
					if (son[fa[x]]==x){
						if (deep[top[x]]<deep[l]){
							ans+=SegmentTree::query_sum(id[l]+1,id[x],1,id[0],1);
							x=l;break;
						} else {
							ans+=SegmentTree::query_sum(id[top[x]]+1,id[x],1,id[0],1);
							x=top[x];
						}
					} else ans+=w[x],x=fa[x];
				}
				while (y!=l){
					if (son[fa[y]]==y){
						if (deep[top[y]]<deep[l]){
							ans+=SegmentTree::query_sum(id[l]+1,id[y],1,id[0],1);
							y=l;break;
						} else {
							ans+=SegmentTree::query_sum(id[top[y]]+1,id[y],1,id[0],1);
							y=top[y];
						}
					} else ans+=w[y],y=fa[y];
				}
				printf("%lld\n",ans+w[l]);
			}
		} else if (ch=='C'){
			int x=read(),delta=read();
			w[x]=delta;
			SegmentTree::update(id[x],1,id[0],1,delta);
		}
		if (k==m) break;
		ch=getchar();while (ch!='Q' && ch!='C') ch=getchar();
	}
	return 0;
}