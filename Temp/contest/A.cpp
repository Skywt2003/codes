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

const int maxn=1e5+5,INF=1e9+5;
int n,a[maxn],num[maxn],sum[maxn];

int myabs(int x){return x<0?-x:x;}

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
	}
	for (int i=1;i<n;i++){
		num[i]=myabs(a[i]-a[i+1])*((i&1)?1:-1);
		sum[i]=sum[i-1]+num[i];
	}
	int lst_min=0,ans=-INF;
	for (int i=1;i<n;i++){
		ans=max(ans,sum[i]-lst_min);
		if ((i&1)==0) lst_min=min(lst_min,sum[i]);
	}
	for (int i=1;i<n;i++) num[i]=-num[i],sum[i]=sum[i-1]+num[i];
	lst_min=sum[1];
	for (int i=1;i<n;i++){
		ans=max(ans,sum[i]-lst_min);
		if ((i&1)) lst_min=min(lst_min,sum[i]);
	}
	printf("%lld\n",ans);
	return 0;
}