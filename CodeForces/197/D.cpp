#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1505,zero=1000;
const int flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m;
char a[maxn][maxn];
bool vis[maxn][maxn];
int visx[maxn][maxn],visy[maxn][maxn];
bool ans=false;

#define xx ((nx+n*800-1)%n+1)
#define yy ((ny+m*800-1)%m+1)

inline void BFS(int sx,int sy){
	queue<pair<int,int> > que;
	while (!que.empty()) que.pop();
	que.push(make_pair(sx,sy));
	visx[sx][sy]=sx;visy[sx][sy]=sy;vis[sx][sy]=true;
	while (!que.empty()){
		pair<int,int> head=que.front();que.pop();
		for (int i=0;i<4;i++){
			int nx=head.first+flg[i][0],ny=head.second+flg[i][1];
			if (a[xx][yy]=='#') continue;
			if (vis[xx][yy] && (visx[xx][yy]!=nx || visy[xx][yy]!=ny)) {ans=true;return;} else
			if (vis[xx][yy] && (visx[xx][yy]==nx && visy[xx][yy]==ny)) continue;
			if (!vis[xx][yy]) vis[xx][yy]=true,visx[xx][yy]=nx,visy[xx][yy]=ny;
			que.push(make_pair(nx,ny));
		}
	}
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	int sx=-1,sy=-1;
	for (int i=1;i<=n&&sx==-1;i++){
		for (int j=1;j<=m&&sy==-1;j++) if (a[i][j]=='S'){
			sx=i;sy=j;
			break;
		}
	}
	BFS(sx,sy);
	if (ans) printf("Yes\n"); else printf("No\n");
	return 0;
}