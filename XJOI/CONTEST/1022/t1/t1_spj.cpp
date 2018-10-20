#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define int long long
using namespace std;

const int maxn=55,flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m;
bool a[maxn][maxn];
bool vis[maxn][maxn];

struct info{
	int x,y,s;
};
queue<info> que;

inline bool check(int x,int y){
	if (x<1||y<1||x>n||y>m||a[x][y]) return false;
	return !vis[x][y];
}

inline int BFS(int sx,int sy){
	while (!que.empty()) que.pop();
	que.push((info){sx,sy,0});
	vis[sx][sy]=true;
	while (!que.empty()){
		info now=que.front();que.pop();
		for (int i=0;i<4;i++) if (check(now.x+flg[i][0],now.y+flg[i][1])){
			que.push((info){now.x+flg[i][0],now.y+flg[i][1],now.s+1});
			vis[now.x+flg[i][0]][now.y+flg[i][1]]=true;
			if (now.x+flg[i][0]==n && now.y+flg[i][1]==m) return now.s+1;
		}
	}
	return -1;
}

signed main(){
	scanf("%lld%lld",&n,&m);
	char ch=getchar();while (ch!='.'&&ch!='#') ch=getchar();
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			a[i][j]=ch=='#';
			if (i==n&&j==m) continue;
			ch=getchar();while (ch!='.'&&ch!='#') ch=getchar();
		}
	}
	printf("%lld\n",BFS(1,1));
	return 0;
}