#include<bits/stdc++.h>

#define int long long

using namespace std;

const int maxn=2005;
const int tt=1e9+7;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,m;
char a[maxn][maxn];
int rock[maxn][maxn];
int sum_r[maxn][maxn],sum_d[maxn][maxn];
int d[maxn][maxn],r[maxn][maxn];

int sd[maxn][maxn],sr[maxn][maxn]; // DP prefix sum

signed main(){
	n=read(); m=read();
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);

	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			rock[i][j]=a[i][j]=='R';

	if (n==1 && m==1){printf("%lld\n",1-rock[1][1]);return 0;}

	for (int i=1;i<=n;i++)
		for (int j=m;j>=1;j--)
			sum_r[i][j]=sum_r[i][j+1]+rock[i][j];
	for (int j=1;j<=m;j++)
		for (int i=n;i>=1;i--)
			sum_d[i][j]=sum_d[i+1][j]+rock[i][j];

	for (int i=n;i>=1;i--){
		for (int j=m;j>=1;j--){
			// for (int t=1;t<=n-sum_d[i+1][j]-i;t++) d[i][j]=(d[i][j]+r[i+t][j])%tt;
			// for (int t=1;t<=m-sum_r[i][j+1]-j;t++) r[i][j]=(r[i][j]+d[i][j+t])%tt;
			d[i][j] = (sr[i+1][j] - sr[i+ (n-sum_d[i+1][j]-i) +1][j] + tt)%tt;
			r[i][j] = (sd[i][j+1] - sd[i][j+ (m-sum_r[i][j+1]-j) +1] + tt)%tt;
			if (i==n && j==m) d[i][j]=r[i][j]=1-rock[i][j]; else
			if (i==n){d[i][j]=0; if (sum_r[i][j+1]) r[i][j]=0;} else 
			if (j==m){r[i][j]=0; if (sum_d[i+1][j]) d[i][j]=0;}

			sr[i][j]=(sr[i+1][j]+r[i][j])%tt;
			sd[i][j]=(sd[i][j+1]+d[i][j])%tt;
		}
	}

	printf("%lld\n",(d[1][1]+r[1][1])%tt);
	return 0;
}