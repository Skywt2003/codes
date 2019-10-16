#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=998244353;
const int maxn=205,maxm=1e5+5;

int n,m,w[maxn];
int f[maxn][maxm];

signed main(){
	n=read(); m=read();
	for (int i=1;i<=n;i++) w[i]=read()%tt;

	f[0][0]=1;

	for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++){
			f[i][j]=f[i-1][j];
			if (j>=1) f[i][j]=(f[i][j]+(f[i][j-1])*w[i]%tt)%tt;
		}

	// for (int i=1;i<=n;i++){
	// 	for (int j=1;j<=m;j++) printf("F[%lld][%lld] = %lld\n",i,j,f[i][j]);
	// 	printf("\n");
	// }
	
	printf("%lld\n",f[n][m]);
	return 0;
}