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

const int maxn=505;

int n,m,b,tt;
int f[maxn][maxn];
int a[maxn];

inline void plus_mod(int &x,int y){x=(x+y)%tt;}

signed main(){
	n=read();m=read();b=read();tt=read();
	for (int i=1;i<=n;i++) a[i]=read();
	f[0][0]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	for (int k=a[i];k<=b;k++)
		plus_mod(f[j][k],f[j-1][k-a[i]]);
	int ans=0;
	for (int i=0;i<=b;i++) plus_mod(ans,f[m][i]);
	printf("%lld\n",ans);
	return 0;
}