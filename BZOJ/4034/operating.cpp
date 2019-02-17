#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005,maxe=2*maxn;

int n,m;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int fa[maxn],son[maxn],top[maxn],id[maxn],size[maxn],deep[maxn],w[maxn];

#define ls (p<<1)
#define rs ((p<<1)+1)
#define mid (((tr-tl)>>1)+tl)

namespace SegmentTree{
	int tree[maxn*4],tag[maxn*4];

	void push_down(int tl,int tr,int p){
		tree[ls]+=tag[p]*(mid-tl+1);
		tree[rs]+=tag[p]*(tr-mid);
		tag[ls]+=tag[p];tag[rs]+=tag[p];
		tag[p]=0;
	}

	void update(int sl,int sr,int tl,int tr,int p,int delta){
		if (sl<=tl && tr<=sr){
			tree[p]+=delta*(tr-tl+1);
			tag[p]+=delta;
			return;
		}
		push_down(tl,tr,p);
		if (sl<=mid  ) update(sl,sr,tl,mid,ls,delta);
		if (mid+1<=sr) update(sl,sr,mid+1,tr,rs,delta);
		tree[p]=tree[ls]+tree[rs];
	}

	int query(int sl,int sr,int tl,int tr,int p){
		if (sl<=tl && tr<=sr) return tree[p];
		push_down(tl,tr,p);
		int ret=0;
		if (sl<=mid  ) ret+=query(sl,sr,tl,mid,ls);
		if (mid+1<=sr) ret+=query(sl,sr,mid+1,tr,rs);
		return ret;
	}
}

void add_edge(int x,int y){
	tot++;to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

void make_tree(int x){
	size[x]=1;
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		fa[to[i]]=x;deep[to[i]]=deep[x]+1;
		make_tree(to[i]);
		size[x]+=size[to[i]];
		if (son[x]==0 || size[to[i]]>size[son[x]]) son[x]=to[i];
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

signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) w[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}
	deep[1]=1;top[1]=1;
	make_tree(1);make_chain(1);
	for (int i=1;i<=n;i++) SegmentTree::update(id[i],id[i],1,id[0],1,w[i]);

	while (m--){
		int opt=read();
		if (opt==1){
			int x=read(),delta=read();
			w[x]+=delta;
			SegmentTree::update(id[x],id[x],1,id[0],1,delta);
		} else if (opt==2){
			int x=read(),delta=read();
			SegmentTree::update(id[x],id[x]+size[x]-1,1,id[0],1,delta);
		} else if (opt==3){
			int x=read(),ans=0;
			while (x){
				ans+=SegmentTree::query(id[top[x]],id[x],1,id[0],1);
				x=fa[top[x]];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}