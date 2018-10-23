#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

#define int long long
using namespace std;

const int tt=1e9+7;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=5e5+25;
int n,m;
int sum[maxn],c[maxn][20];

inline void build_com(){
	c[0][0]=1;
	c[1][0]=c[1][1]=1;
	for (int i=2;i<=n+20;i++){
		c[i][0]=1;
		if (i<20) c[i][i]=1;
		for (int j=1;j<min((int)20,i);j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%tt;
	}
}

signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read();
	build_com();
	for (int i=1;i<=m;i++){
		int l=read(),r=read(),k=read();
		for (int j=l;j<=r;j++) sum[j]=(sum[j]+c[j+k-l][k])%tt;
	}
	for (int i=1;i<=n;i++) printf("%lld\n",sum[i]);
	printf("\n");
	return 0;
}