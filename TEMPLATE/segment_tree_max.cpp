// 190217 关于“最大值”的线段树，只支持单点修改

#include<bits/stdc++.h>
using namespace std;

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