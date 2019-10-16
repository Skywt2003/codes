#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn=1005,maxm=205;
const int tt=1000000007;

int n,m,K;
char a[maxn],b[maxm];

int f[2][maxm][maxm][2];

signed main(){
	scanf("%lld%lld%lld",&n,&m,&K);
	scanf("%s%s",a+1,b+1);

	f[0][0][0][0]=f[1][0][0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			for (int k=1;k<=K;k++){
				f[i&1][j][k][0] = (f[i&1^1][j][k][0]+f[i&1^1][j][k][1])%tt,
				f[i&1][j][k][1] = (f[i&1^1][j-1][k-1][0]+f[i&1^1][j-1][k-1][1]+f[i&1^1][j-1][k][1]) * (a[i]==b[j])%tt;
			}
	}
	printf("%lld\n",(f[n&1][m][K][0]+f[n&1][m][K][1])%tt);
	return 0;
}