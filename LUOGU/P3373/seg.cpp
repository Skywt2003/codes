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
	int tree[maxn*4];
    int tag_add[maxn*4],tag_mul[maxn*4];

	inline void clear(){
		memset(tree,0,sizeof(tree));
		memset(tag_add,0,sizeof(tag_add));
        memset(tag_mul,0,sizeof(tag_mul));
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
		tree[ls]=tree[ls]*tag_mul[p]+tag_add[p];
		tree[rs]=tree[rs]*tag_mul[p]+tag_add[p];
        tag_mul[ls]*=tag_mul[p];tag_mul[rs]*=tag_mul[p];
		tag_add[ls]+=tag_add[p];tag_add[rs]+=tag_add[p];
		tag_add[p]=0;
	}

	inline void update_add(int sl,int sr,int tl,int tr,int p,int delta){
		if (sl<=tl && tr<=sr){
			tree[p]+=delta;
			tag_add[p]+=delta*(tr-tl+1);
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
			tag_add[p]*=delta;
            tag_mul[p]*=delta;
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