// 181105
// 190801 Update: use `class` instead of `namespace`

#include<bits/stdc++.h>
#define int long long

const int maxn=1e5+5;

#define ls (p<<1)
#define rs (p<<1|1)
#define mid (((tr-tl)>>1)+tl)

class segmentTree{
	private:
		int tree[maxn*4],tag[maxn*4];

		void push_down(int tl,int tr,int p){
			tree[ls]+=tag[p]*(mid-tl+1);
			tree[rs]+=tag[p]*(tr-mid);
			tag[ls]+=tag[p];tag[rs]+=tag[p];
			tag[p]=0;
		}

	public:
		segmentTree(){
			memset(tree,0,sizeof(tree));
			memset(tag,0,sizeof(tag));
		}

		void build_tree(int tl,int tr,int p,int* &a){
			if (tl==tr){
				tree[p]=a[tl];
				return;
			}
			build_tree(tl,mid  ,ls,a);
			build_tree(mid+1,tr,rs,a);
			tree[p]=tree[ls]+tree[rs];
		}

		void update(int sl,int sr,int tl,int tr,int p,int delta){
			if (sl<=tl && tr<=sr){
				tree[p]+=delta*(tr-tl+1);
				tag[p]+=delta;
				return;
			}
			push_down(tl,tr,p);
			if (sl  <=mid) update(sl,sr,tl,mid  ,ls,delta);
			if (mid+1<=sr) update(sl,sr,mid+1,tr,rs,delta);
			tree[p]=tree[ls]+tree[rs];
		}

		int query(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return tree[p];
			push_down(tl,tr,p);
			int ret=0;
			if (sl  <=mid) ret+=query(sl,sr,tl,mid  ,ls);
			if (mid+1<=sr) ret+=query(sl,sr,mid+1,tr,rs);
			return ret;
		}
};

#undef ls
#undef rs
#undef mid