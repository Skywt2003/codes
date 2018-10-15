#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=20,flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,cnt,a[maxn][maxn];
inline bool check(int x,int y){
	if (x<1||y<1||x>n||y>n||a[x][y]!=-1) return false;
	return true;
}
int main(){
	scanf("%d",&n);
	memset(a,255,sizeof(a));
	int xx=1,yy=1,ff=1;a[xx][yy]=cnt=1;
	while (1){
		if (!check(xx+flg[ff][0],yy+flg[ff][1])) ff=(ff+1)%4;
		if (!check(xx+flg[ff][0],yy+flg[ff][1])) break;
		xx+=flg[ff][0];yy+=flg[ff][1];a[xx][yy]=++cnt;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<n;j++) printf("%d ",a[i][j]);
		printf("%d\n",a[i][n]);
	}
	return 0;
}
