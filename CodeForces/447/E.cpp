#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

const int maxn=300005,N=300000;
const int tt=1000000009;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

namespace Fibonacci{
	int f[maxn],sum[maxn];

	inline void build(){
		f[1]=f[2]=1;
		for (int i=3;i<=N;i++) f[i]=(f[i-1]+f[i-2])%tt,sum[i]=(sum[i-1]+f[i])%tt;
	}

	inline int query(int a,int b,int n){
		if (n==0) return 0; else
		if (n==1) return a; else
		if (n==2) return b; else
		return (f[n-2]*a%tt+f[n-1]*b%tt)%tt;
	}

	inline int get_sum(int a,int b,int n){
		return (a*sum[n-2]%tt+b*sum[n-1]%tt)%tt;
	}
}

#define ls ((p<<1))
#define rs ((p<<1)+1)

namespace SegmentTree{
	int sum[maxn*4];
	int tag_a[maxn*4],tag_b[maxn*4];

	inline void update(int sl,int sr,int tl,int tr,int p,int a,int b){
		if (sl<=tl && tr<=sr){
			sum[p]=(sum[p]+Fibonacci::get_sum(a,b,tr-tl+1))%tt;
			tag_a[p]+=a;tag_b[p]+=b;
			return;
		}
		int mid=((tr-tl)>>1)+tl;
		int as=Fibonacci::query(tag_a[p],tag_b[p],mid+1);
		int bs=Fibonacci::query(tag_a[p],tag_b[p],mid+2);
		if (sl<=mid  ) update(sl,sr,tl,mid,ls,a,b);
		if (mid+1<=sr) update(sl,sr,mid+1,tr,rs,as,bs);
	}
	
	inline void push_down(int tl,int tr,int p){
		int mid=((tr-tl)>>1)+tl;
		int as=Fibonacci::query(tag_a[p],tag_b[p],mid+1);
		int bs=Fibonacci::query(tag_a[p],tag_b[p],mid+2);
		tag_a[ls]+=tag_a[p];tag_b[ls]+=tag_b[p];
		tag_a[rs]+=as;      tag_b[rs]+=bs;
	}

	inline int query(int sl,int sr,int tl,int tr,int p){
		if (sl<=tl && tr<=sr) return sum[p];
		push_down(tl,tr,p);
		int mid=((tr-tl)>>1)+tl;
		int ret=0;
		if (sl<=mid  ) ret+=query(sl,sr,tl,mid,ls);
		if (mid+1<=sr) ret+=query(sl,sr,mid+1,tr,rs);
		return ret%tt;
	}
}

int n,m;
int a[maxn],sum[maxn];

signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read(),sum[i]=(sum[i-1]+a[i])%tt;
	for (int i=1;i<=m;i++){
		int opt=read(),x=read(),y=read();
		if (opt==1){
			SegmentTree::update(x,y,1,n,1,1,1);
		} else if (opt==2){
			int ans=SegmentTree::query(x,y,1,n,1);
			printf("%lld\n",(ans+sum[y]-sum[x-1])%tt);
		}
	}
	return 0;
}