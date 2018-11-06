#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define int long long

using namespace std;

const int INF=0x3f3f3f3f;
const int maxn=50000;

int n,a[maxn],ans;

#define mid (((tr-tl)>>1)+tl)
#define ls (p<<1)
#define rs ((p<<1)+1)

typedef pair<pair<int,int>,pair<int,int> > double_pair;

template <typename T>
T max3(const T & e1, const T & e2, const T & e3) {
	return max(max(e1, e2), e3);
}

namespace data{
	int sum[maxn];
	
	inline void build_prefix_sum(){
		for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	}

	inline int get_sum(int l,int r){
		return sum[r]-sum[l-1];
	}
}

namespace SegmentTree{
	int tree[maxn*4],pre[maxn*4],suf[maxn*4];
	
	inline int init(){
		memset(tree,0,sizeof(tree));
		memset(pre,0,sizeof(pre));
		memset(suf,0,sizeof(suf));
	}

	inline void build_tree(int tl,int tr,int p){
		if (tl==tr){
			tree[p]=pre[p]=suf[p]=a[tl];
			return;
		}
		build_tree(tl,mid  ,ls);
		build_tree(mid+1,tr,rs);
		tree[p]=suf[ls]+pre[rs];
		pre[p]=max(pre[ls],data::get_sum(tl,mid  )+pre[rs]);
		suf[p]=max(suf[rs],suf[ls]+data::get_sum(mid+1,tr));
	}

	inline double_pair query(int sl,int sr,int tl,int tr,int p){
		double_pair ret=make_pair(make_pair(0,0),make_pair(tl,tr));
		if (sl<=tl && tr<=sr){
			ans=max(ans,tree[p]);
			ret.first=make_pair(pre[p],suf[p]);
			ret.second=make_pair(tl,tr);
			if (ret.first.first<0 && ret.first.second<0){
				if (ret.first.first < ret.first.second) ret.first.first=0;
				else ret.first.second=0;
			} else {
				if (ret.first.first  < 0) ret.first.first =0;
				if (ret.first.second < 0) ret.first.second=0;
			}
			printf("query(%lld, %lld, %lld, %lld, %lld) = %lld, %lld\n",sl,sr,tl,tr,p,ret.first.first,ret.first.second);
			return ret;
		}
		if (sl<=mid && mid+1<=sr){
			double_pair p1=query(sl,sr,tl,mid  ,ls);
			double_pair p2=query(sl,sr,mid+1,tr,rs);
			ret.first.first =max(p1.first.first ,data::get_sum(p1.second.first ,mid  )+p2.first.first );
			ret.first.second=max(p2.first.second,p1.first.second+data::get_sum(mid+1,p2.second.second));
			if (ret.first.first<0 && ret.first.second<0){
				if (ret.first.first < ret.first.second) ret.first.first=0;
				else ret.first.second=0;
			} else {
				if (ret.first.first <0) ret.first.first =0;
				if (ret.first.second<0) ret.first.second=0;
			}
			ans=max(ans,p1.first.second+p2.first.first);
			printf("query(%lld, %lld, %lld, %lld, %lld) = %lld, %lld\n",sl,sr,tl,tr,p,ret.first.first,ret.first.second);
			return ret;
		} else if (sl  <=mid){
			ret=query(sl,sr,tl,mid,ls);
			printf("query(%lld, %lld, %lld, %lld, %lld) = %lld, %lld\n",sl,sr,tl,tr,p,ret.first.first,ret.first.second);
			return ret;
		} else if (mid+1<=sr){
			ret=query(sl,sr,mid+1,tr,rs);
			printf("query(%lld, %lld, %lld, %lld, %lld) = %lld, %lld\n",sl,sr,tl,tr,p,ret.first.first,ret.first.second);
			return ret;
		}
	}
}

namespace FastIO{
	inline int read(){
		int ret=0,f=1;char ch=getchar();
		while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
		while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
		return ret*f;
	}
}

signed main(){
	n=FastIO::read();
	for (int i=1;i<=n;i++) a[i]=FastIO::read();
	data::build_prefix_sum();
	SegmentTree::build_tree(1,n,1);
	int q=FastIO::read();
	for (int i=1;i<=q;i++){
		int x=FastIO::read(),y=FastIO::read();
		ans=-INF;
		double_pair p=SegmentTree::query(x,y,1,n,1);
		printf("%lld\n",max(ans,max(p.first.first,p.first.second)));

		// printf("===\n");
		// printf("%lld %lld %lld\n",ans,p.first.first,p.first.second);
		// printf("%lld %lld\n",p.second.first,p.second.second);
		// printf("===\n");
	}
	return 0;
}