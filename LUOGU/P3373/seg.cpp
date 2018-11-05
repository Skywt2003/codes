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

namespace SegmentTree{
	int tree[maxn*4],tag[maxn*4];

	inline void clear(){
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
	}

	inline void build_tree(int tl,int tr,int p,int* &a){
		clear();
		if (tl==tr){
			tree[p]=a[tl];
			return;
		}
		build_tree(tl,mid  ,ls,a);
		build_tree(mid+1,tr,rs,a);
		tree[p]=tree[ls]+tree[rs];
	}

	inline void push_down(int tl,int tr,int p){
		tree[ls]+=tag[p]*(mid-tl+1);
		tree[rs]+=tag[p]*(tr-mid);
		tag[ls]+=tag[p];tag[rs]+=tag[p];
		tag[p]=0;
	}

	inline void update_add(int sl,int sr,int tl,int tr,int p,int delta){
		if (sl<=tl && tr<=sr){
			tree[p]+=delta;
			tag[p]+=delta;
			return;
		}
		push_down(tl,tr,p);
		if (sl  <=mid) update_add(sl,sr,tl,mid  ,ls,delta);
		if (mid+1<=sr) update_add(sl,sr,mid+1,tr,rs,delta);
		tree[p]=tree[ls]+tree[rs];
	}

	inline void update_mul(int sl,int sr,int tl,int tr,int p,int delta){
		if (sl<=tl && tr<=sr){
			tree[p]+=delta;
			tag[p]+=delta;
			return;
		}
		push_down(tl,tr,p);
		if (sl  <=mid) update_mul(sl,sr,tl,mid  ,ls,delta);
		if (mid+1<=sr) update_mul(sl,sr,mid+1,tr,rs,delta);
		tree[p]=tree[ls]+tree[rs];
	}

	inline int query(int sl,int sr,int tl,int tr,int p){
		if (sl<=tl && tr<=sr) return tree[p];
		push_down(tl,tr,p);
		int ret=0;
		if (sl  <=mid) ret+=query(sl,sr,tl,mid  ,ls);
		if (mid+1<=sr) ret+=query(sl,sr,mid+1,tr,rs);
	}
}

signed main(){

}