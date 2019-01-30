#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

const int maxn=2005;
const int tt=1e9+7;

int n,m;
int f[maxn][maxn];
int sum[maxn],nsum[maxn];

inline void plus_mod(int &x,int y){
	x=(x+y)%tt;
}

signed main(){
	scanf("%lld%lld",&n,&m);
	memset(sum,0,sizeof(sum));memset(nsum,0,sizeof(nsum));
	for (int i=2;i<=m;i++) f[1][i]=1,nsum[i]=(nsum[i-1]+f[1][i])%tt;
	for (int i=2;i<=n;i++){
		for (int j=2;j<=m;j++) sum[j]=nsum[j],nsum[j]=0;
		f[i][1]=1;
		for (int j=2;j<=m;j++) f[i][j]=(f[i][j-1]+sum[j])%tt,nsum[j]=(nsum[j-1]+f[i][j])%tt;
	}

	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=2;j<=m;j++){
			plus_mod(ans,(f[i][j]-f[i-1][j]+tt)%tt*f[n-i+1][j]%tt*(m-j+1)%tt);
		}
	}

	printf("%lld\n",ans);
	return 0;
}