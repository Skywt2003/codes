#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int tt=1e9+7,INF=1e18;
const int maxn=45;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int min(int x,int y){
	return x<y?x:y;
}
inline int max(int x,int y){
	return x>y?x:y;
}

int n;
int a[maxn];
int L[maxn],R[maxn];
int f[maxn][maxn][maxn*maxn][2];

inline void plus_mod(int &x,int y){
	x=(x+y)%tt;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),L[i]=(a[i]==-1)?(0):(a[i]),R[i]=(a[i]==-1)?(40):(a[i]);
	f[0][0][0][0]=1; L[0]=R[0]=0;
	for (int i=0;i<n;i++){
		for (int j=L[i];j<=R[i];j++){
			for (int k=0;k<=40*i;k++){
				for (int t=L[i+1];t<j  && t<=((i)?(k/i):(INF));t++) plus_mod(f[i+1][t][k+t][1],f[i][j][k][0]);
				for (int t=j;t<=R[i+1] && t<=((i)?(k/i):(INF));t++) plus_mod(f[i+1][t][k+t][0],(f[i][j][k][0]+f[i][j][k][1])%tt);
			}
		}
	}
	int ans=0;
	for (int i=L[n];i<=R[n];i++)
		for (int j=0;j<=40*40;j++)
			plus_mod(ans,(f[n][i][j][0]+f[n][i][j][1])%tt);
	printf("%lld\n",ans);
	return 0;
}