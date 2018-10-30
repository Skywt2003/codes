#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=2005,INF=0x3f3f3f3f3f3f3f3f;
int n,m,a[maxn][maxn],b[maxn][maxn];
bool vis[maxn][maxn];
int max_num=-INF,min_num=INF;
int L,R,ans=INF;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline bool check(int x){
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=m;i++) vis[0][i]=true;
	for (int i=1;i<=n;i++){ // 钦定左上角有 min_num
		for (int j=1;j<=m;j++) if (a[i][j]-min_num<=x && vis[i-1][j]) vis[i][j]=true; else break;
	}
	// printf("check %lld\n",x);
	// for (int i=1;i<=n;i++){
	// 	for (int j=1;j<=m;j++) printf("%lld ",vis[i][j]);
	// 	printf("\n");
	// }
	int another_min=INF;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) if (!vis[i][j]) another_min=min(another_min,a[i][j]);
	}
	// printf("Another-Min = %lld\n",another_min);
	return (max_num-another_min <= x);
}

inline void rotate(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) b[i][j]=a[i][j];
	}
	swap(n,m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) a[i][j]=b[j][n-i+1];
	}
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			a[i][j]=read();
			max_num=max(max_num,a[i][j]);
			min_num=min(min_num,a[i][j]);
		}
	}

	for (int i=0;i<4;i++){
		if (i) rotate();
		// printf("I = %lld\n",i);
		// for (int is=1;is<=n;is++){
		// 	for (int js=1;js<=m;js++) printf("%lld ",a[is][js]);
		// 	printf("\n");
		// }
		L=0,R=max_num-min_num;
		while (L<=R){
			int mid=((R-L)>>1)+L;
			if (check(mid)) ans=min(ans,mid),R=mid-1; else L=mid+1;
		}
	}

	printf("%lld\n",(ans==INF)?(-1):(ans));
	return 0;
}