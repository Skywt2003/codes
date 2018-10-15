#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int flg[5][2]={{-1,0},{0,1},{1,0},{0,-1},{0,0}};
int ans=1<<30,INF=1<<30;
bool vis[5][5],now[5][5],rst[5][5];
inline void DFS(int x,int y,int sum){
	if (sum>ans) return;
	if (x==5){
		for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++) rst[i][j]=vis[i][j];
		for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++) if (now[i][j]){
			for (int k=0;k<5;k++) rst[i+flg[k][0]][j+flg[k][1]]=1-rst[i+flg[k][0]][j+flg[k][1]];
		}
		bool bcpl=true,wcpl=true;
		for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++){
			if ( rst[i][j]&&bcpl) bcpl=false;
			if (!rst[i][j]&&wcpl) wcpl=false;
			if ((!bcpl)&&(!wcpl)) break;
		}
		if (wcpl||bcpl) ans=sum;
		return;
	}
	int xn=x,yn=y;
	if (y==4) xn++,yn=1; else yn++;
	now[x][y]=1;
	DFS(xn,yn,sum+1);
	now[x][y]=0;
	DFS(xn,yn,sum);
}
int main(){
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	char ch=getchar();while (ch!='w'&&ch!='b') ch=getchar();
	for (int i=1;i<=4;i++)
	for (int j=1;j<=4;j++){
		vis[i][j]=ch=='b';
		if (i==4&&j==4) continue;
		ch=getchar();while (ch!='w'&&ch!='b') ch=getchar();
	}
	DFS(1,1,0);
	if (ans==INF) printf("Impossible\n"); else printf("%d\n",ans);
	return 0;
}
