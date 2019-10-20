#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;
const int tt=1e9+7;

int n,m;

int f[maxn][2];
int ans=0;

signed main(){
	n=read();m=read();
	
	memset(f,0,sizeof(f));
	f[0][0]=f[0][1]=1;
	f[1][0]=f[1][1]=1;
	for (int i=2;i<=n;i++)
		f[i][1]=(f[i-2][0]+f[i-1][0])%tt,
		f[i][0]=(f[i-2][1]+f[i-1][1])%tt;
	ans=(ans+f[n][0]+f[n][1])%tt;

	// for (int i=1;i<=n;i++) printf("%lld %lld\n",f[i][0],f[i][1]);
	// printf("%lld\n",ans);

	memset(f,0,sizeof(f));
	f[0][0]=f[0][1]=1;
	f[1][0]=f[1][1]=1;
	for (int i=2;i<=m;i++)
		f[i][1]=(f[i-2][0]+f[i-1][0])%tt,
		f[i][0]=(f[i-2][1]+f[i-1][1])%tt;
	ans=(ans+f[m][0]+f[m][1])%tt;

	printf("%lld\n",(ans-2+tt)%tt);
	return 0;
}