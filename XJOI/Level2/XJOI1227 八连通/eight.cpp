#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105,flg[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int n,m,ans=0;
bool a[maxn][maxn];
inline bool check(int x,int y){
    if (x<1||y<1||x>n||y>m) return false;
    return !a[x][y];
}
inline void DFS(int x,int y){
    a[x][y]=1;
    for (int i=0;i<8;i++) if (check(x+flg[i][0],y+flg[i][1])) DFS(x+flg[i][0],y+flg[i][1]);
}
int main(){
    scanf("%d%d",&n,&m);
    char ch=getchar();while (ch!='W'&&ch!='.') ch=getchar();
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++){
        a[i][j]=ch!='W';
        if (i==n&&j==m) continue;
        ch=getchar();while (ch!='W'&&ch!='.') ch=getchar();
    }
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++) if (!a[i][j]) {ans++;DFS(i,j);}
    printf("%d\n",ans);
    return 0;
}