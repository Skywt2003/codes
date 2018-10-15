#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10,flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,sum=0;
bool a[maxn][maxn],vis[maxn][maxn];
inline bool check(int x,int y){
    if (x<1||y<1||x>n||y>m) return false;
    if (vis[x][y]||a[x][y]) return false;
    return true;
}
inline void DFS(int x,int y){
    if (x==n&&y==m) {sum++;return;}
    for (int i=0;i<4;i++) if (check(x+flg[i][0],y+flg[i][1])){
        vis[x+flg[i][0]][y+flg[i][1]]=1;
        DFS(x+flg[i][0],y+flg[i][1]);
        vis[x+flg[i][0]][y+flg[i][1]]=0;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    char ch=getchar();while (ch!='*'&&ch!='#') ch=getchar();
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++){
        a[i][j]=ch=='#';
        if (i==n&&j==m) continue;
        ch=getchar();while (ch!='*'&&ch!='#') ch=getchar();
    }
    vis[1][1]=1;
    DFS(1,1);
    printf("%d\n",sum);
    return 0;
}