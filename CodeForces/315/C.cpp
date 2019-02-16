#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5,INF=1e9+5;

int n,k;
int a[maxn],sum[maxn];

signed main(){
	n=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int tus=0;
	for (int i=1;i<=n;i++){
		int ii=i-tus;
		// printf("%lld now: %lld\n",i,sum[i-1]-(ii-1)*(n-tus-ii)*a[i]);
		if (sum[i-1]-(ii-1)*(n-tus-ii)*a[i] < k){
			printf("%lld\n",i);
			sum[i]=sum[i-1];tus++;
		} else sum[i]=sum[i-1]+a[i]*(ii-1);
	}
	return 0;
}