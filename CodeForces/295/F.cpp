#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5;
const pair<int,int> zero_pair=make_pair(0,0);
int n,m,N;
map<int,int> to;
int numto[maxn*2],sx[maxn];

#define ls ((p<<1))
#define rs ((p<<1)+1)
#define mid (((tr-tl)>>1)+tl)

struct sts{
	int x,y,z;
}zero_sts=(sts){0,0,0};

namespace SegmentTree{
	int tree[maxn*4],sum[maxn*4],num[maxn*4];

	inline void change(int x,int delta,int tl,int tr,int p){
		if (x==tl && tl==tr){
			sum[p]+=delta*numto[x];
			num[p]+=delta;
			return;
		}
		if (x<=mid  ) change(x,delta,tl,mid,ls);
		if (mid+1<=x) change(x,delta,mid+1,tr,rs);
		num[p]=num[ls]+num[rs];
		tree[p]=tree[ls]+tree[rs]+num[ls]*sum[rs]-num[rs]*sum[ls];
		sum[p]=sum[rs]+sum[ls];
		// printf("[%lld,%lld]: sum=%lld tree=%lld num=%lld\n",tl,tr,sum[p],tree[p],num[p]);
	}

	inline sts query(int sl,int sr,int tl,int tr,int p){
		if (sl<=tl && tr<=sr){
			// printf("tl=%lld tr=%lld sum=%lld tree=%lld num=%lld\n",tl,tr,sum[p],tree[p],num[p]);
			return (sts){sum[p],tree[p],num[p]};
		}
		sts ret1=zero_sts,ret2=zero_sts;
		if (sl<=mid  ) ret1=query(sl,sr,tl,mid,ls);
		if (mid+1<=sr) ret2=query(sl,sr,mid+1,tr,rs);
		sts ret=(sts){ret1.x+ret2.x,  ret1.y+ret2.y+ret1.z*ret2.x-ret2.z*ret1.x,  ret1.z+ret2.z};
		// printf("query (%lld %lld %lld %lld) : sum=%lld tree=%lld num=%lld\n",sl,sr,tl,tr,ret.x,ret.y,ret.z);;
		return ret;
	}
}

struct opt{
	int x,y,z;
}opts[maxn];

signed main(){
	n=read();
	vector<int> vec;vec.clear();
	for (int i=1;i<=n;i++) numto[i]=sx[i]=read(),vec.push_back(numto[i]);
	m=read();
	for (int i=1;i<=m;i++){
		opts[i].x=read(),opts[i].y=read(),opts[i].z=read();
		if (opts[i].x==1) numto[opts[i].y]+=opts[i].z,vec.push_back(numto[opts[i].y]);
		else vec.push_back(opts[i].y),vec.push_back(opts[i].z);
	}
	sort(vec.begin(),vec.end());unique(vec.begin(),vec.end()); N=vec.size();
	for (int i=1;i<=N;i++) numto[i]=vec[i-1],to[numto[i]]=i;//,cout<<i<<" --> "<<vec[i-1]<<endl;
	
	for (int i=1;i<=n;i++) SegmentTree::change(to[sx[i]],1,1,N,1);
	for (int i=1;i<=m;i++){
		if (opts[i].x==1){
			SegmentTree::change(to[sx[opts[i].y]],-1,1,N,1);
			sx[opts[i].y]+=opts[i].z;
			SegmentTree::change(to[sx[opts[i].y]],1,1,N,1);
		} else {
			sts ans=SegmentTree::query(to[opts[i].y],to[opts[i].z],1,N,1);
			printf("%lld\n",ans.y);
			// printf(" - %lld %lld %lld\n",ans.x,ans.y,ans.z);
		}
	}
	return 0;
}