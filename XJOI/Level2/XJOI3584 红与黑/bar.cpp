#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=25,flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,sx,sy,sum=0;
bool a[maxn][maxn];
inline bool check(int x,int y){
    if (x<1||y<1||x>n||y>m) return false;
    return true;
}
inline void DFS(int x,int y){
    sum++;
    a[x][y]=1;
    for (int i=0;i<4;i++) if (check(x+flg[i][0],y+flg[i][1])&&(!a[x+flg[i][0]][y+flg[i][1]])) DFS(x+flg[i][0],y+flg[i][1]);
}
int main(){
    scanf("%d%d",&n,&m);
    char ch=getchar();while (ch!='.'&&ch!='#'&&ch!='@') ch=getchar();
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++){
        a[i][j]=ch=='#';
        if (ch=='@') sx=i,sy=j;
        if (i==n&&j==m) continue;
        ch=getchar();while (ch!='.'&&ch!='#'&&ch!='@') ch=getchar();
    }
    DFS(sx,sy);
    printf("%d\n",sum);
    return 0;
}