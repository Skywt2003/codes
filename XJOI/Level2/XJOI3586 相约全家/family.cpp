#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=205,maxv=2005,flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,xa,ya,xb,yb,INF,dst[2][maxn][maxn];
bool a[maxn][maxn],isf[maxn][maxn],vis[maxn][maxn];
struct Que{
    int x,y;
}que[maxv];
inline bool check(int x,int y){
    if (x<1||y<1||x>n||y>m) return false;
    if (vis[x][y]||a[x][y]) return false;
    return true;
}
inline void BFS(int xs,int ys,int k){
    memset(vis,0,sizeof(vis));
    memset(dst[k],63,sizeof(dst[k]));INF=dst[k][0][0];
    vis[xs][ys]=1;
    int head=0,tail=1;
    dst[k][xs][ys]=0;
    que[tail].x=xs;que[tail].y=ys;
    while (head!=tail){
        head=(head+1)%maxv;
        int xx=que[head].x,yy=que[head].y;
        for (int i=0;i<4;i++) if (check(xx+flg[i][0],yy+flg[i][1])){
            dst[k][xx+flg[i][0]][yy+flg[i][1]]=dst[k][xx][yy]+1;
            vis[xx+flg[i][0]][yy+flg[i][1]]=1;
            tail=(tail+1)%maxv;
            que[tail].x=xx+flg[i][0];que[tail].y=yy+flg[i][1];
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    char ch=getchar();while (ch!='#'&&ch!='.'&&ch!='F'&&ch!='@'&&ch!='&') ch=getchar();
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++){
        if (ch=='@') {xa=i;ya=j;a[i][j]=0;} else
        if (ch=='&') {xb=i;yb=j;a[i][j]=0;} else
        if (ch=='#') a[i][j]=1; else
        if (ch=='.') a[i][j]=0; else
        if (ch=='F') {a[i][j]=0;isf[i][j]=1;};
        if (i==n&&j==m) continue;
        ch=getchar();while (ch!='#'&&ch!='.'&&ch!='F'&&ch!='@'&&ch!='&') ch=getchar();
    }
    BFS(xa,ya,0);
    BFS(xb,yb,1);
    int ans=INF;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++) if (isf[i][j]&&dst[0][i][j]+dst[1][i][j]<ans) ans=dst[0][i][j]+dst[1][i][j];
    if (ans==INF) printf("Meeting cancelled\n"); else printf("%d\n",ans);
    return 0;
}