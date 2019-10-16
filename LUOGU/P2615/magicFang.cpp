#include<bits/stdc++.h>

using namespace std;

const int maxn=50;

int n;

int a[maxn][maxn];

signed main(){
	scanf("%d",&n);

	int x=1,y=(n+1)/2; a[x][y]=1;
	for (int k=2;k<=n*n;k++){
		if (x==1 && y!=n) x=n,y++; else
		if (x!=1 && y==n) x--,y=1; else
		if (x==1 && y==n) x++; else
		if (x!=1 && y!=n) (a[x-1][y+1]==0)?x--,y++:x++;
		a[x][y]=k;
	}

	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}