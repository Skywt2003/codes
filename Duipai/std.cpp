// Floyd 暴力

#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

#define write(_) cout<<#_<<" = "<<_<<endl

const int maxn=105;
int n,ans=0;
int f[maxn][maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void Floyd(){
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++) if (i!=k)
	for (int j=1;j<=n;j++) if (j!=i&&j!=k){
		if (f[i][k]+f[k][j]<f[i][j]) f[i][j]=f[j][i]=f[i][k]+f[k][j];
	}
}

signed main(){
	memset(f,0x3f,sizeof(f));
	n=read();
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=1;i<=n;i++){
		int x=read(),y=read(),w=read();
		if (w<f[x][y]) f[x][y]=f[y][x]=w;
	}
	Floyd();
	pair <int,int> rec;
	int ans=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		if (f[i][j]>ans) ans=f[i][j],rec=make_pair(i,j);
	printf("%lld\n",ans);
	return 0;
}
