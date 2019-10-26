#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=205;

int n,m;

int SG[maxn][maxn];


int DFS(int n,int m){
	if (~SG[n][m]) return SG[n][m];
	
	bool vis[maxn];
	memset(vis,0,sizeof(vis));
	for (int i=2;i<=n/2;i++) vis[DFS(i,m)^DFS(n-i,m)]=true;
	for (int i=2;i<=m/2;i++) vis[DFS(n,i)^DFS(n,m-i)]=true;

	for (int i=0;;i++) if (!vis[i]) return SG[n][m]=i;
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	memset(SG,-1,sizeof(SG));
	while (~scanf("%lld%lld",&n,&m)) printf(DFS(n,m)?"WIN\n":"LOSE\n");
	return 0;
}