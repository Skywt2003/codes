#pragma GCC optimize(2)

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

const int maxn=1e5+5,INF=1e9+5;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,m;

struct object{
	int x,y,t;
	int id,rank,ans,upper;
}a[maxn],b[maxn];
bool cmp(object aa,object bb){return aa.x<bb.x;}
bool cmp_ti(object aa,object bb){return aa.t<bb.t;}
bool cmp_id(object aa,object bb){return aa.id<bb.id;}

#define ls (p<<1)
#define rs ((p<<1)+1)

int num[maxn*2],busid[maxn*2];

void discrete(){ // Descrete the time. Buses only.
	for (int i=1;i<=n;i++) a[i].rank=i,busid[i]=a[i].id,num[i]=a[i].t;
}

void make_upper(){ // Build lower_bound(b[i].t) so that set is unnecessary
	int j=n;
	for (int i=m;i>=1;i--){
		while (j-1>=1 && a[j-1].t>=b[i].t) j--;
		b[i].upper=a[j].t;
	}
}

namespace SegmentTree{ // Naïve SegmentTree.
	int tree[4*maxn];

	void insert(int x,int tl,int tr,int p,int delta){
		if (x==tl && tl==tr){
			tree[p]=max(tree[p],delta);
			return;
		}
		int mid=((tr-tl)>>1)+tl;
		if (x<=mid  ) insert(x,tl,mid,ls,delta); else
		if (mid+1<=x) insert(x,mid+1,tr,rs,delta);
		tree[p]=max(tree[ls],tree[rs]);
	}

	int query(int tl,int tr,int p,int x,int t){
		if (num[tr]<t || tree[p]<x) return INF;
		if (tl==tr && tree[p]>=x) return tl;
		int mid=((tr-tl)>>1)+tl;
		if (num[mid]<t || tree[ls]<x) return query(mid+1,tr,rs,x,t); else {
			int xx=query(tl,mid,ls,x,t),yy=query(mid+1,tr,rs,x,t);
			return min(xx,yy);
		}
	}
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].t=read(),a[i].id=i;
	for (int i=1;i<=m;i++) b[i].x=read(),b[i].y=read(),b[i].t=read(),b[i].id=i;
	sort(a+1,a+1+n,cmp_ti);
	discrete();
	sort(b+1,b+1+m,cmp_ti);
	make_upper();
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+m,cmp);
	
	int j=0;
	for (int i=1;i<=m;i++){
		while (j+1<=n && a[j+1].x<=b[i].x) SegmentTree::insert(a[j+1].rank,1,n,1,a[j+1].y),j++;
		if (b[i].t>num[n]) b[i].ans=INF; else{
			int tmp=b[i].upper;
			b[i].ans=SegmentTree::query(1,n,1,b[i].y,tmp);
		}
	}
	sort(b+1,b+1+m,cmp_id);
	for (int i=1;i<=m;i++) printf("%lld ",((b[i].ans==INF)?-1:busid[b[i].ans]));
	printf("\n");
	return 0;
}