#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

#define int long long
#define sqr(_) ((_)*(_))
using namespace std;

const int tt=998244353;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e7+5,N=1e7;
int T,n;
int ans[maxn];

namespace mymath{
	inline int qsm(int a,int b){
		int ret=1,w=a%tt;
		while (b){
			if (b&1) ret=ret*w%tt;
			b>>=1;w=w*w%tt;
		}
		return ret;
	}

	int inv[maxn];

	inline void make_inverse(int n){
		inv[1]=1;
		for (int i=2;i<=n;i++) inv[i]=(tt-tt/i)*inv[tt%i]%tt;
	}
}

namespace Problem_Solving{
	inline void solve(){
		int sum=0;
		for (int i=1;i<=N;i++){
			sum=(sum+1*mymath::inv[i])%tt;
			ans[i]=(i-sum+tt)%tt;
		}
	}
}

signed main(){
	mymath::make_inverse(N);
	Problem_Solving::solve();
	T=read();
	while (T--){
		n=read();
		printf("%lld\n",ans[n]);
	}
	return 0;
}