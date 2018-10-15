#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=205,maxv=407,flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,xs,ys,xt,yt,INF,a[maxn][maxn],dst[maxn][maxn];
struct Que{
    int x,y;
}que[maxv];
bool vis[maxn][maxn];
inline bool check(int x,int y){
    if (x<1||y<1||x>n||y>m) return false;
    if (a[x][y]==2) return false;
    return true;
}
inline void SPFA(){
    memset(dst,63,sizeof(dst));INF=dst[0][0];
    vis[xs][ys]=1;dst[xs][ys]=0;
    int head=0,tail=1;
    que[tail].x=xs;que[tail].y=ys;
    while (head!=tail){
        head=(head+1)%maxv;
        int xx=que[head].x,yy=que[head].y;
        vis[xx][yy]=false;
        for (int i=0;i<4;i++) if (check(xx+flg[i][0],yy+flg[i][1])&&(dst[xx][yy]+a[xx+flg[i][0]][yy+flg[i][1]]+1<dst[xx+flg[i][0]][yy+flg[i][1]])){
            dst[xx+flg[i][0]][yy+flg[i][1]]=dst[xx][yy]+a[xx+flg[i][0]][yy+flg[i][1]]+1;
            if (~vis[xx+flg[i][0]][yy+flg[i][1]]){
                vis[xx+flg[i][0]][yy+flg[i][1]]=true;
                tail=(tail+1)%maxv;
                que[tail].x=xx+flg[i][0];
                que[tail].y=yy+flg[i][1];
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    char ch=getchar();while (ch!='#'&&ch!='.'&&ch!='G'&&ch!='M'&&ch!='@') ch=getchar();
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++){
        if (ch=='M') {xt=i,yt=j,a[i][j]=0;} else
        if (ch=='@') {xs=i,ys=j,a[i][j]=0;} else
        if (ch=='.') a[i][j]=0; else
        if (ch=='#') a[i][j]=2; else
        if (ch=='G') a[i][j]=1;
        if (i==n&&j==m) continue;
        ch=getchar();while (ch!='#'&&ch!='.'&&ch!='G'&&ch!='M'&&ch!='@') ch=getchar();
    }
    SPFA();
    if (dst[xt][yt]!=INF) printf("%d\n",dst[xt][yt]); else printf("You can't save Mengxin\n");
    return 0;
}