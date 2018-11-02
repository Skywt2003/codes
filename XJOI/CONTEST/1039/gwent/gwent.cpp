#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=998244353;
const int maxn=1005,maxk=1e6+5,N=1e6;
int T,n,a[maxn];
int need[maxn][2];

namespace math{
	int fact[maxk];

	inline void build_fact(){
		fact[0]=1;
		for (int i=1;i<=N;i++) fact[i]=fact[i-1]*i%tt;
	}

	inline int qsm(int a,int b){
		int ret=1,w=a%tt;
		while (b){
			if (b&1) ret=ret*w%tt;
			w=w*w%tt;b>>=1;
		}
		return ret;
	}

	inline int C(int x,int y){
		return fact[x]*qsm(fact[y],tt-2)%tt*qsm(fact[x-y],tt-2)%tt;
	}
}

inline void debug_math(int x,int y){
	printf("C(%lld, %lld) = %lld\n",x,y,math::C(x,y));
}

signed main(){
	T=read();
	math::build_fact();
	while (T--){
		n=read();
		int sum=0;
		for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
		int std_num=sum/n;

		for (int i=1;i<=n;i++) need[i][0]=need[i-1][0]+((std_num>a[i])?std_num-a[i]:0);
		for (int i=n;i>=1;i--) need[i][1]=need[i+1][1]+((std_num>a[i])?std_num-a[i]:0);

		int ans=1;
		for (int i=1;i<n;i++){
			if (a[i]>std_num){
				int delta=min(a[i]-std_num,need[i+1][1]);
				ans=ans*math::C(a[i],delta)%tt;
				a[i+1]+=delta;a[i]-=delta;
			}
		}
		for (int i=n;i>1;i--){
			if (a[i]>std_num){
				int delta=min(a[i]-std_num,need[i-1][0]);
				ans=ans*math::C(a[i],delta)%tt;
				a[i-1]+=delta;a[i]-=delta;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}