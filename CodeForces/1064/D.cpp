/*
 * Codeforces Round #516
 * D - Labyrinth
 * 181014 By SkyWT
 */

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl;

#define int long long

int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2005,flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}},INF=1<<30;
int n,m,r,c,ls,rs,ans=0;
char a[maxn][maxn];
bool vis[maxn][maxn];

struct info{
	int x,y;
};

info dst[maxn][maxn];
queue <info> que;

inline void init(){
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		dst[i][j]=(info){INF,INF};
}

inline bool check(int x,int y){
	if (x<1||y<1||x>n||y>m||a[x][y]=='*') return false;
	return true;
}

inline void SPFA(){
	que.push((info){r,c});
	dst[r][c]=(info){0,0};
	while (!que.empty()){
		info head=que.front();que.pop();
		vis[head.x][head.y]=false;
		for (int i=0;i<4;i++){
			int nx=head.x+flg[i][0],ny=head.y+flg[i][1];
			if (!check(nx,ny)) continue;
			int now1=(i==3),now2=(i==1);
			if (dst[head.x][head.y].x+now1>ls || dst[head.x][head.y].y+now2>rs) continue;
			if (dst[head.x][head.y].x+now1<dst[nx][ny].x && dst[head.x][head.y].y+now2<dst[nx][ny].y){
				dst[nx][ny].x=dst[head.x][head.y].x+now1;
				dst[nx][ny].y=dst[head.x][head.y].y+now2;
				if (!vis[nx][ny]){
					vis[nx][ny]=true;
					que.push((info){nx,ny});
				}
			}
		}
	}
}

signed main(){
	n=read();m=read();
	r=read();c=read();
	ls=read();rs=read();
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	init();
	SPFA();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		if (dst[i][j].x!=INF || dst[i][j].y!=INF) ans++;
	printf("%lld\n",ans);
	return 0;
}