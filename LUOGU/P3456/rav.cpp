#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005,flg[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int n,a[maxn][maxn],ans1=0,ans2=0;
bool vis[maxn][maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline bool check(int x,int y){
	if (x<1||y<1||x>n||y>n) return false;
	return true;
}
inline bool DFS(int x,int y,int p){ //p=0£ºÉ½·å  p=1£ºÉ½¹È 
	vis[x][y]=true;
	bool ret=true;
	for (int i=0;i<8;i++) if (check(x+flg[i][0],y+flg[i][1])&&a[x+flg[i][0]][y+flg[i][1]]!=a[x][y]){
		if (p==0&&a[x][y]<a[x+flg[i][0]][y+flg[i][1]]) {ret=false;break;}
		if (p==1&&a[x][y]>a[x+flg[i][0]][y+flg[i][1]]) {ret=false;break;}
	}
	for (int i=0;i<8;i++) if (check(x+flg[i][0],y+flg[i][1])&&vis[x+flg[i][0]][y+flg[i][1]]==false&&a[x+flg[i][0]][y+flg[i][1]]==a[x][y]) ret=ret&&DFS(x+flg[i][0],y+flg[i][1],p);
	return ret;
}
int main(){
	memset(a,-1,sizeof(a));
	n=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) a[i][j]=read();
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) if (vis[i][j]==false&&DFS(i,j,0)) ans1++;
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) if (vis[i][j]==false&&DFS(i,j,1)) ans2++;
	printf("%d %d\n",ans1,ans2);
	return 0;
}
