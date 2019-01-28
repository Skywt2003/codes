#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

const int maxn=300005,N=300000;
const int tt=1000000009;

#define ls ((p<<1))
#define rs ((p<<1)+1)

int n,m;
int a[maxn];

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
		return f[n-2]*a+f[n-1]*b;
	}

	inline int get_sum(int a,int b,int n){
		return a*sum[n-2]+b*sum[n-1];
	}
}

namespace SegmentTree{
	int sum[maxn*4];
	int tag_a[maxn*4],tag_b[maxn*4];
	
	inline void push_down(int tl,int tr,int p){
		int mid=((tr-tl)>>1)+tl;
		int as=Fibonacci::query(tag_a[p],tag_b[p],mid+1);
		int bs=Fibonacci::query(tag_a[p],tag_b[p],mid+2);
		tag_a[ls]+=tag_a[p];tag_b[ls]+=tag_b[p];
		tag_a[rs]+=as;      tag_b[rs]+=bs;
	}

	inline void update(int sl,int sr,int tl,int tr,int p,int a,int b){
		if (tl<=sl && sr<=tr){
			sum[p]+=get_sum(a,b,sr-sl+1);
			return;
		}
		int mid=((tr-tl)>>1)+tl;
		int as=Fibonacci::query(tag_a[p],tag_b[p],mid+1);
		int bs=Fibonacci::query(tag_a[p],tag_b[p],mid+2);
		if (sl<=mid  ) update(sl,sr,tl,mid,ls,a,b);
		if (mid+1<=sr) update(sl,sr,mid+1,tr,rs,)
	}

	inline int query(int sl,int sr,int tl,int tr,int p){

	}
}

signed main(){

}