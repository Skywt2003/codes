#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int tt=1e9+7;
const int maxn=55;
int n=0;
int a[maxn],f[maxn][3];

signed main(){
	char ch=getchar();while (ch<'0'||ch>'9') ch=getchar();
	while (ch!=-1&&ch!=10&&ch!=13){
		a[++n]=ch-'0';
		ch=getchar();
	}
	f[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<i;j++)
			for (int k=0;k<3;k++)
				f[i][(k+a[i])%3]=(f[i][(k+a[i])%3]+f[j][k])%tt;
	int ans=0;
	for (int i=1;i<=n;i++) ans=(ans+f[i][0])%tt;
	printf("%lld\n",ans);
	return 0;
}