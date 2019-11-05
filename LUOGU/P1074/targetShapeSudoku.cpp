#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=10,n=9;

int a[maxn][maxn];

pair<int,int> row[maxn]; // <zero_count, id>

int get_grid(int x,int y){
	if (1<=x && x<=3){
		if (1<=y && y<=3) return 1; else
		if (4<=y && y<=6) return 2; else
		if (7<=y && y<=9) return 3; else
		printf("get_grid(%lld,%lld) | ERROR!\n",x,y);
	} else if (4<=x && x<=6){
		if (1<=y && y<=3) return 4; else
		if (4<=y && y<=6) return 5; else
		if (7<=y && y<=9) return 6; else
		printf("get_grid(%lld,%lld) | ERROR!\n",x,y);
	} else if (7<=x && x<=9){
		if (1<=y && y<=3) return 7; else
		if (4<=y && y<=6) return 8; else
		if (7<=y && y<=9) return 9; else
		printf("get_grid(%lld,%lld) | ERROR!\n",x,y);
	} else printf("get_grid(%lld,%lld) | ERROR!\n",x,y);
}

int get_value(int x,int y){
	if (x==5 && y==5) return 10; else
	if (4<=x&&x<=6 && 4<=y&&y<=6) return 9; else
	if (3<=x&&x<=7 && 3<=y&&y<=7) return 8; else
	if (2<=x&&x<=8 && 2<=y&&y<=8) return 7; else
	if (1<=x&&x<=9 && 1<=y&&y<=9) return 6; else
	printf("get_value(%lld,%lld) | ERROR!\n",x,y);
}

bool vis[3][maxn][maxn]; // 0:row; 1:colm; 2:grid.
int ans=-1;

void DFS(int x,int y,int tot){
	if (x==n && y==n){ans=max(ans,tot);return;}

	y++; if (y>n) x++,y=1;
	int i=row[x].second,j=y;
	if (a[i][j]) return DFS(x,y,tot+get_value(i,j)*a[i][j]);
	for (int now=1;now<=9;now++) if (!vis[0][i][now] && !vis[1][j][now] && !vis[2][get_grid(i,j)][now]){
		vis[0][i][now]=vis[1][j][now]=vis[2][get_grid(i,j)][now]=true;
		DFS(x,y,tot+get_value(i,j)*now);
		vis[0][i][now]=vis[1][j][now]=vis[2][get_grid(i,j)][now]=false;
	}
}

signed main(){
	for (int i=1;i<=n;i++){
		int cnt=0;
		for (int j=1;j<=n;j++){
			a[i][j]=read(),cnt+=a[i][j]==0;
			if (a[i][j]) vis[0][i][a[i][j]]=vis[1][j][a[i][j]]=vis[2][get_grid(i,j)][a[i][j]]=true;
		}
		row[i]=make_pair(cnt,i);
	}
	sort(row+1,row+1+n);
	
	DFS(1,0,0);

	printf("%lld\n",ans);
	return 0;
}