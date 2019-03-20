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

const int maxn=1e5+5;
const int maxe=2*maxn;


class SegmentTree{

	#define mid (((tr-tl)>>1)+tl)
	#define ls ((p<<1))
	#define rs ((p<<1)+1)

	private:
		int tree[maxn];

	public:
		void update(int x,int tl,int tr,int p,int delta){
			if (tl==tr && tl==x){
				tree[x]+=delta;
				return;
			}
			if (x  <=mid) update(x,tl,mid,ls,delta);
			if (mid+1<=x) update(x,mid+1,tr,rs,delta);
			tree[p]=tree[ls]+tree[rs];
		}

		int query(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return tree[p];
			int ret=0;
			if (sl<=mid  ) ret+=query(sl,sr,tl,mid,ls);
			if (mid+1<=sr) ret+=query(sl,sr,mid+1,tr,rs);
			return ret;
		}
};

int n,m,root,tt;

int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int size[maxn],deep[maxn],fa[maxn];
int v[maxn];

void add_edge(int x,int y){
	tot++;to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

namespace HLD{
	int son[maxn],top[maxn],id[maxn];

	void make_tree(int x){
		size[x]=1;
		int max_size=0,k=-1;
		for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
			fa[to[i]]=x;deep[to[i]]=deep[x]+1;
			make_tree(to[i]);
			size[x]+=size[to[i]];
			if (size[to[i]]>max_size) max_size=size[to[i]],k=to[i];
		}
		if (k!=-1) son[x]=k;
	}

	void make_chain(int x){
		id[x]=++id[0];
		if (son[fa[x]]!=x) top[x]=x; else top[x]=top[fa[x]];
		if (son[x]) make_chain(x);
		for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x] && to[i]!=son[x]){
			make_chain(to[i]);
		}
	}

	void change_chain(int x,int y,int delta,SegmentTree &tree){

	}

	int query_chain(int x,int y,SegmentTree &tree){

	}

	void change_subtree(int x,int delta,SegmentTree &tree){

	}

	int query_subtree(int x,SegmentTree &tree){

	}
}
	
SegmentTree tree;

signed main(){
	n=read(),m=read(),root=read(),tt=read();
	for (int i=1;i<=n;i++) v[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}

	deep[root]=1;
	HLD::make_tree(root);
	HLD::make_chain(root);

	while (m--){
		int opt=read();
		switch(opt){
			case 1:
				int x=read(),y=read(),z=read();
				HLD::change_chain(x,y,z,tree);
				break;
			case 2:
				int x=read(),y=read();
				printf("%lld\n",HLD::query_chain(x,y,tree));
				break;
			case 3:
				int x=read(),z=read();
				HLD::change_subtree(x,z,tree);
				break;
			case 4:
				int x=read();
				printf("%lld\n",HLD::query_subtree(x,tree));
				break;
			defalt:
				printf("ERROR!\n");
				break;
		}
	}

	return 0;
}