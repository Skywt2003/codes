#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
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

int n,g[maxn][maxn];
int x[maxn];
int ans[maxn];
bool vis[maxn];

inline void Floyd(){
	for (int i=1;i<=n;i++) g[i][i]=0;
	for (int k=n;k>=1;k--){
		vis[x[k]]=true;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (i!=j && j!=x[k] && i!=x[k]){
			g[i][j]=min(g[i][j],g[i][x[k]]+g[x[k]][j]);
		}
		for (int i=1;i<=n;i++) if (vis[i])
		for (int j=1;j<=n;j++) if (vis[j]){
			ans[k]+=g[i][j];
		}
	}
}

signed main(){
	n=read();
	memset(g,63,sizeof(g));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) g[i][j]=read();
	}
	for (int i=1;i<=n;i++) x[i]=read();
	Floyd();
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}