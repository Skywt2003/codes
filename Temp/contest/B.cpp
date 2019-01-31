#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=55;
const int flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int n,m;
char a[maxn][maxn];
bool vis[maxn][maxn];
bool ans=false;

inline bool check(int x,int y){
	if (x<1||y<1||x>n||y>m) return false;
	return true;
}

inline void DFS(int x,int y,int lx,int ly){
	if (ans) return;
	vis[x][y]=true;
	for (int i=0;i<4;i++) if (check(x+flg[i][0],y+flg[i][1]) && (x+flg[i][0]!=lx||y+flg[i][1]!=ly) && a[x+flg[i][0]][y+flg[i][1]]==a[x][y]){
		if (vis[x+flg[i][0]][y+flg[i][1]]){
			ans=true;
			return;
		}
		DFS(x+flg[i][0],y+flg[i][1],x,y);
	}
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			memset(vis,0,sizeof(vis));
			DFS(i,j,-1,-1);
			if (ans){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}