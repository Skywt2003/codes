#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int NEG_INF=0x8080808080808080;

const int maxn=100005;

#define ls (p<<1)
#define rs ((p<<1)+1)
#define mid (((tr-tl)>>1)+tl)

class segmentTree{
	private:
		int tree_max[maxn*4],tree_min[maxn*4];

	public:
		segmentTree(){
			memset(tree_max,0,sizeof(tree_max));
			memset(tree_min,0,sizeof(tree_min));
		}

		void update(int x,int tl,int tr,int p,int delta){
			if (x==tl && tl==tr){
				tree_max[p]=tree_min[p]=delta;
				return;
			}
			if (x  <=mid) update(x,tl,mid  ,ls,delta);
			if (mid+1<=x) update(x,mid+1,tr,rs,delta);
			tree_max[p]=max(tree_max[ls],tree_max[rs]);
			tree_min[p]=min(tree_min[ls],tree_min[rs]);
		}

		int query_max(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return tree_max[p];
			int ret=0;
			if (sl  <=mid) ret=max(ret,query_max(sl,sr,tl,mid  ,ls));
			if (mid+1<=sr) ret=max(ret,query_max(sl,sr,mid+1,tr,rs));
			return ret;
		}

		int query_min(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return tree_min[p];
			int ret=INF;
			if (sl  <=mid) ret=min(ret,query_min(sl,sr,tl,mid  ,ls));
			if (mid+1<=sr) ret=min(ret,query_min(sl,sr,mid+1,tr,rs));
			return ret;
		}
};

#undef ls
#undef rs
#undef mid

segmentTree t;

int n,m,cnt=0;

signed main(){
	n=read(); m=read();
	for (int i=1;i<=n;i++){
		int opt=read();
		if (opt==1){
			int x=read();
			t.update(++cnt,1,n,1,x);
		} else {
			printf("%lld\n",t.query_max(max(1ll,cnt-m+1),cnt,1,n,1) - t.query_min(max(1ll,cnt-m+1),cnt,1,n,1));
		}
	}
	return 0;
}