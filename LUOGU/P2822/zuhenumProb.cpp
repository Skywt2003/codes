#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2005,N=2000;

int T,n,m,k;
int c[maxn][maxn],sum[maxn][maxn];

void build_c(int tt){
	c[0][0]=1%tt;
	c[1][0]=c[1][1]=1%tt;
	for (int i=2;i<=N;i++){
		c[i][0]=c[i][i]=1%tt;
		for (int j=1;j<i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%tt;
	}
	for (int i=0;i<=N;i++){
		sum[i][0]=c[i][0]==0;
		for (int j=1;j<=N;j++)
			sum[i][j]=sum[i][j-1]+(c[i][j]==0);
	}
}

signed main(){
	T=read(); k=read();
	build_c(k);
	while (T--){
		n=read(),m=read();
		int ans=0;
		for (int i=1;i<=n;i++) ans+=sum[i][min(i,m)];
		printf("%lld\n",ans);
	}
	return 0;
}