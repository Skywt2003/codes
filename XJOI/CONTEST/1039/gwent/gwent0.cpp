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
	int inv[maxk];
	int fact[maxk];

	inline void build_inverse(){
		inv[1]=1;
		for (int i=2;i<=N;i++) inv[i]=(tt-(tt/i))*inv[tt%i]%tt;
	}

	inline void build_fact(){
		fact[0]=1;
		for (int i=1;i<=N;i++) fact[i]=fact[i-1]*i%tt;
	}

	inline int C(int x,int y){
		return fact[x]*inv[fact[y]]%tt*inv[fact[x-y]]%tt;
	}
}

inline void debug_math(int x,int y){
	printf("C(%lld, %lld) = %lld\n",x,y,math::C(x,y));
}

signed main(){
	T=read();
	math::build_inverse();
	math::build_fact();
	while (T--){
		n=read();
		int sum=0;
		for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
		int std_num=sum/n;

		for (int i=1;i<=n;i++) need[i][0]=need[i-1][0]+((std_num>a[i])?std_num-a[i]:0);
		for (int i=n;i>=1;i--) need[i][1]=need[i+1][1]+((std_num>a[i])?std_num-a[i]:0);

		int ans=1,now=0;
		for (int i=1;i<=n;i++){
			if (a[i]>std_num){
				ans=ans*math::C(a[i],need[i+1][1])%tt;
				now+=need[i+1][1];
				a[i]-=need[i+1][1];
			} else {
				int delta=std_num-a[i];
				if (delta>now) continue;
				now-=delta;a[i]=std_num;
				if (now) ans=ans*(a[i]+1)%tt;
			}
		}
		// printf("%lld\n",ans);
		for (int i=n;i>=1;i--){
			if (a[i]>std_num){
				ans=ans*math::C(a[i],need[i-1][0])%tt;
				now+=need[i-1][0];
				a[i]-=need[i-1][0];
			} else {
				int delta=std_num-a[i];
				// printf("i=%lld now=%lld delta=%lld\n",i,now,delta);
				if (delta>now) continue;
				now-=delta;a[i]=std_num;
				if (now) ans=ans*(a[i]+1)%tt;
			}
		}
		printf("%lld\n",ans);
	}
}