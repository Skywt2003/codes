#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=105;
int n,m,c,q;
int color[maxn][maxn];
int _left[maxn][maxn],_right[maxn][maxn],_up[maxn][maxn],_down[maxn][maxn];

inline int min4(int a,int b,int c,int d){
	int ret=a;
	if (b<ret) ret=b;
	if (c<ret) ret=c;
	return d<ret?d:ret;
}

int main(){
	scanf("%d%d%d%d",&n,&m,&c,&q);
	
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++){
		scanf("%d",&color[i][j]);
		_left[i][j]=(color[i][j]==color[i][j-1])*_left[i][j-1]+1;
		_up[i][j]=(color[i][j]==color[i-1][j])*_up[i-1][j]+1;
	}
	for (int i=n;i>=1;i--)
	for (int j=m;j>=1;j--){
		_right[i][j]=(color[i][j]==color[i][j+1])*_right[i][j+1]+1;
		_down[i][j]=(color[i][j]==color[i+1][j])*_down[i+1][j]+1;
	}

	// printf("Left:\n");
	// for (int i=1;i<=n;i++){
	// 	for (int j=1;j<=m;j++) printf("%d ",_left[i][j]);
	// 	printf("\n");
	// }
	
	while (q--){
		char now=getchar();while (now!='Q'&&now!='C') now=getchar();
		if (now=='C'){
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			color[x][y]=k;
			for (int i=1;i<=n;i++) _up[i][y]=(color[i][y]==color[i-1][y])*_up[i-1][y]+1;
			for (int i=n;i>=1;i--) _down[i][y]=(color[i][y]==color[i+1][y])*_down[i+1][y]+1;
			for (int j=1;j<=m;j++) _left[x][j]=(color[x][j]==color[x][j-1])*_left[x][j-1]+1;
			for (int j=m;j>=1;j--) _right[x][j]=(color[x][j]==color[x][j+1])*_right[x][j+1]+1;
		} else {
			int ans=0;
			int clr;scanf("%d",&clr);
			for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) if (color[i][j]==clr) ans+=min4(_left[i][j],_right[i][j],_up[i][j],_down[i][j])-1;
			printf("%d\n",ans);
		}
	}
	return 0;
}