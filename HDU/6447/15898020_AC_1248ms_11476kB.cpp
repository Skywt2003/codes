#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define CLEAR(_) memset(_,0,sizeof(_))
using namespace std;
const int maxn=200005;

int T,n,ans,f[maxn];
struct Village{
	int x,y,ys,w;
};
vector <Village> a;

namespace SegmentTree{
	int tree[maxn*4],tag[maxn*4];
	inline void clear(){
		CLEAR(tree);CLEAR(tag);
	}
	inline void push_down(int tl,int tr,int p){
		int mid=((tr-tl)>>1)+tl;
		tree[p<<1]=max(tree[p<<1],tag[p]);
		tag[p<<1]+=tag[p];
		tree[(p<<1)+1]=max(tree[(p<<1)+1],tag[p]);
		tag[(p<<1)+1]+=tag[p];
		tag[p]=0;
	}
	inline void update(int sl,int sr,int tl,int tr,int delta,int p){
		if (sl<=tl&&sr>=tr){
			tree[p]=max(tree[p],delta);
			tag[p]+=delta;
			return;
		}
		push_down(tl,tr,p);
		int mid=((tr-tl)>>1)+tl;
		if (sl<=mid) update(sl,sr,tl,mid,delta,p<<1);
		if (mid<sr)  update(sl,sr,mid+1,tr,delta,(p<<1)+1);
		tree[p]=max(tree[p<<1],tree[(p<<1)+1]);
	}
	inline int query(int sl,int sr,int tl,int tr,int p){
		if (sl>sr) return 0;
		if (sl<=tl&&sr>=tr) return tree[p];
		int ret=0;
		push_down(tl,tr,p);
		int mid=((tr-tl)>>1)+tl;
		if (sl<=mid) ret=max(ret,query(sl,sr,tl,mid,p<<1));
		if (mid<sr)  ret=max(ret,query(sl,sr,mid+1,tr,(p<<1)+1));
		return ret;
	}
}

inline void init(){
	ans=0;
	a.clear();CLEAR(f);
	SegmentTree::clear();
}

inline bool compare_x(Village aa,Village bb){
	return (aa.x<bb.x)||((aa.x==bb.x)&&(aa.y>bb.y));
}
inline bool compare_y(Village aa,Village bb){
	return aa.y<bb.y;
}

/* 
 * 要先对 y 坐标离散化，不然没法搞
 */
inline void discrete(){
	sort(a.begin(),a.end(),compare_y);
	int cnt=0;
	for (int i=0;i<a.size();i++){
		cnt+=(bool)((i==0)||(a[i].y!=a[i-1].y));
		a[i].ys=cnt;
	}
}

int main(){
	scanf("%d",&T);
	while (T--){
		init();
		scanf("%d",&n);
		for (int i=0;i<n;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			a.push_back((Village){x,y,0,z});
		}
		discrete();
		sort(a.begin(),a.end(),compare_x);
		for (int i=0;i<n;i++){
			f[i]=a[i].w+SegmentTree::query(1,a[i].ys-1,1,n*2,1);
			// printf("F[%d]=%d\n",i,f[i]);
			ans=max(ans,f[i]);
			SegmentTree::update(a[i].ys,a[i].ys,1,n*2,f[i],1);
		}
		printf("%d\n",ans);
	}
	return 0;
}