#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

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
	int id,ans;
}a[maxn],b[maxn];
bool cmp(object aa,object bb){
	return aa.x<bb.x;
}

bool cmp_id(object aa,object bb){
	return aa.id<bb.id;
}

#define ls (p<<1)
#define rs ((p<<1)+1)

int allt,num[maxn*2],busid[maxn*2];
map<int,int> to;
void discrete(){ // Descrete the time.
	to.clear();
	vector<int> vec;vec.clear();
	for (int i=1;i<=n;i++) vec.push_back(a[i].t);
	for (int i=1;i<=m;i++) vec.push_back(b[i].t);
	sort(vec.begin(),vec.end()); unique(vec.begin(),vec.end());
	allt=0;
	for (int i=0;i<(int)vec.size();i++){
		to[vec[i]]=i+1;num[i+1]=vec[i];allt++;
		if (i+1<(int)vec.size() && vec[i+1]<vec[i]) break;
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

	int query(int x,int t){
		if (tree[1]<x) return -1;
		int L=t,R=allt,ret=allt,p=1;
		while (L<=R){
			int mid=((R-L)>>1)+L;
			if (tree[ls]>=x) ret=mid,p=ls,R=mid-1; else p=rs,L=mid+1;
		}
		return ret;
	}
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].t=read(),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=m;i++) b[i].x=read(),b[i].y=read(),b[i].t=read(),b[i].id=i;
	sort(b+1,b+1+m,cmp);
	discrete();
	
	int j=0;
	for (int i=1;i<=m;i++){
		while (j+1<=n && a[j+1].x<=b[i].x) SegmentTree::insert(to[a[j+1].t],1,allt,1,a[j+1].y),j++;
		b[i].ans=SegmentTree::query(b[i].y,to[b[i].t]);
	}
	sort(a+1,a+1+n,cmp_id);
	memset(busid,-1,sizeof(busid));
	for (int i=1;i<=n;i++) busid[to[a[i].t]]=i;
	sort(b+1,b+1+m,cmp_id);
	for (int i=1;i<=m;i++) printf("%lld ",(b[i].ans==-1)?-1:busid[b[i].ans]);
	printf("\n");
	return 0;
}