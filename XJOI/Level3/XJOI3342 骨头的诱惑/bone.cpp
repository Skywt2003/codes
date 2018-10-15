#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10,maxt=55,flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,t,s_x,t_x,s_y,t_y;
bool map[maxn][maxn],aflg=true,vis[maxn][maxn][maxt];
inline bool check(int x,int y){
    if (x<1||y<1||x>n||y>m) return false;
    if (map[x][y]) return false;
    return true;
}
inline int myabs(int x){
    if (x<0) return -x; else return x;
}
inline void DFS(int x,int y,int stp){
    if (!aflg||stp>t) return;
    if (vis[x][y][stp]) return;
    vis[x][y][stp]=1;
    if (stp+myabs(t_y-y)+myabs(t_x-x)-1>t) return;
    if (x==t_x&&y==t_y&&stp==t){printf("YES\n");aflg=false;return;}
    for (int i=0;i<4;i++) if (check(x+flg[i][0],y+flg[i][1])){
        DFS(x+flg[i][0],y+flg[i][1],stp+1);
        if (!aflg) return;
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&t);
    char ch=getchar();while (ch!='S'&&ch!='X'&&ch!='D'&&ch!='.') ch=getchar();
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++){
        map[i][j]=ch=='X';
        if (ch=='S') s_x=i,s_y=j;
        if (ch=='D') t_x=i,t_y=j;
        if (i==n&&j==m) continue;
        ch=getchar();while (ch!='S'&&ch!='X'&&ch!='D'&&ch!='.') ch=getchar();
    }
    DFS(s_x,s_y,0);
    if (aflg) printf("NO\n");
    return 0;
}