#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long

using namespace std;

const int maxn=1e5+5;

#define ls (p<<1)
#define rs ((p<<1)+1)
#define mid (((tr-tl)>>1)+tl)

int tt;

namespace SegmentTree{
	int tree[maxn*4];
	int tag_add[maxn*4],tag_mul[maxn*4];

	inline void init(int n){
		memset(tree,0,sizeof(tree));
		memset(tag_add,0,sizeof(tag_add));
		for (int i=1;i<=4*n;i++) tag_mul[i]=1;
	}

	inline void build_tree(int tl,int tr,int p,int a[]){
		if (tl==tr){
			tree[p]=a[tl]%tt;
			tag_mul[p]=1;
			return;
		}
		build_tree(tl,mid  ,ls,a);
		build_tree(mid+1,tr,rs,a);
		tree[p]=(tree[ls]+tree[rs])%tt;
		tag_mul[p]=1;
	}

	inline void push_down(int tl,int tr,int p){
		tree[ls]=(tree[ls]*tag_mul[p]%tt+tag_add[p]*(mid-tl+1)%tt)%tt;
		tree[rs]=(tree[rs]*tag_mul[p]%tt+tag_add[p]*(tr-mid  )%tt)%tt;
		tag_add[ls]=(tag_add[ls]*tag_mul[p]+tag_add[p])%tt;
		tag_add[rs]=(tag_add[rs]*tag_mul[p]+tag_add[p])%tt;
		tag_mul[ls]=tag_mul[ls]*tag_mul[p]%tt;
		tag_mul[rs]=tag_mul[rs]*tag_mul[p]%tt;
		tag_mul[p]=1;tag_add[p]=0;
	}

	inline void update_add(int sl,int sr,int tl,int tr,int p,int delta){
		if (sl<=tl && tr<=sr){
			tree[p]=(tree[p]+delta*(tr-tl+1)%tt)%tt;
			tag_add[p]=(tag_add[p]+delta)%tt;
			return;
		}
		push_down(tl,tr,p);
		if (sl  <=mid) update_add(sl,sr,tl,mid  ,ls,delta);
		if (mid+1<=sr) update_add(sl,sr,mid+1,tr,rs,delta);
		tree[p]=(tree[ls]+tree[rs])%tt;
	}

	inline void update_mul(int sl,int sr,int tl,int tr,int p,int delta){
		if (sl<=tl && tr<=sr){
			tree[p]=tree[p]*delta%tt;
			tag_mul[p]=tag_mul[p]*delta%tt;
			tag_add[p]=tag_add[p]*delta%tt;
			return;
		}
		push_down(tl,tr,p);
		if (sl  <=mid) update_mul(sl,sr,tl,mid  ,ls,delta);
		if (mid+1<=sr) update_mul(sl,sr,mid+1,tr,rs,delta);
		tree[p]=(tree[ls]+tree[rs])%tt;
	}

	inline int query(int sl,int sr,int tl,int tr,int p){
		if (sl<=tl && tr<=sr) return tree[p]%tt;
		push_down(tl,tr,p);
		int ret=0;
		if (sl  <=mid) ret=(ret+query(sl,sr,tl,mid  ,ls))%tt;
		if (mid+1<=sr) ret=(ret+query(sl,sr,mid+1,tr,rs))%tt;
		return ret;
	}
}

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,m;
int a[maxn];

signed main(){
	n=read();m=read();tt=read();
	for (int i=1;i<=n;i++) a[i]=read()%tt;
	SegmentTree::build_tree(1,n,1,a);

	for (int i=1;i<=m;i++){
		int opt=read();
		if (opt==1){
			int x=read(),y=read(),k=read();
			SegmentTree::update_mul(x,y,1,n,1,k%tt);
		} else if (opt==2){
			int x=read(),y=read(),k=read();
			SegmentTree::update_add(x,y,1,n,1,k%tt);
		} else if (opt==3){
			int x=read(),y=read();
			printf("%lld\n",SegmentTree::query(x,y,1,n,1)%tt);
		}
	}

	// for (int i=1;i<=n;i++) printf("%lld ",SegmentTree::query(i,i,1,n,1));printf("\n");

	return 0;
}