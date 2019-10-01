#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=55;
const int INF=0x3f3f3f3f;
const int flg[6][2]={{-2,0},{-1,-1},{0,-2},{2,0},{1,1},{0,2}};

int n;
int a[maxn][maxn];

int q[maxn][maxn][maxn][maxn];

int total_query=0;
bool fnd=false;

int query(int x1,int y1,int x2,int y2){
    if (x1>x2 || y1>y2) swap(x1,x2),swap(y1,y2);
    if (q[x1][y1][x2][y2]!=-1) return q[x1][y1][x2][y2];
    total_query++;
    // if (total_query > n*n) printf("**ERROR**: TOO MANY QUERIES\n");
    printf("? %d %d %d %d\n",x1,y1,x2,y2);
    fflush(stdout);
    // q[x1][y1][x2][y2]=read();
    scanf("%d",&q[x1][y1][x2][y2]);
    return q[x1][y1][x2][y2];
}

bool check(int x,int y){
    if (x<1||y<1||x>n||y>n) return false;
    return true;
}

signed main(){
    memset(q,-1,sizeof(q));
    n=read();
    memset(a,-1,sizeof(a));
    a[1][1]=1; a[n][n]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) if (a[i][j]!=-1){
            for (int k=0;k<6;k++) if (check(i+flg[k][0],j+flg[k][1])){
                if (a[i+flg[k][0]][j+flg[k][1]]!=-1) continue;
                int f=query(i,j,i+flg[k][0],j+flg[k][1]);
                a[i+flg[k][0]][j+flg[k][1]]=(f)?a[i][j]:(1-a[i][j]);
            }
        }
    for (int k=0;k<=3 && fnd==false;k++){
        for (int i=1;i<=n && fnd==false;i++)
            for (int j=1;j<=n && fnd==false;j++){
                int x1,x2,x3,x4,y1,y2,y3,y4;
                if (k==0){  //^^^^
                    x1=i,x2=i,x3=i,x4=i;
                    y1=j,y2=j+1,y3=j+2,y4=j+3;
                } else if (k==1){ // ^^|
                    x1=i,x2=i,x3=i,x4=i+1;
                    y1=j,y2=j+1,y3=j+2,y4=j+2;
                } else if (k==2){ // ^|
                    x1=i,x2=i+1,x3=i+1,x4=i+1;
                    y1=j,y2=j,y3=j+1,y4=j+1;
                } else if (k==3){ // |
                    x1=i,x2=i+1,x3=i+2,x4=i+3;
                    y1=j,y2=j,y3=j,y4=j;
                }
                if ((!check(x1,y1)) || (!check(x2,y2)) || (!check(x3,y3)) || (!check(x4,y4))) continue;
                if ((query(x1,y1,x3,y3)^query(x2,y2,x4,y4))==0){
                    // printf("(%d,%d) (%d,%d) (%d,%d) (%d,%d)\n",x1,y1,x2,y2,x3,y3,x4,y4);
                    int f=query(x1,y1,x4,y4);
                    if (f){
                        if (a[x1][y1]!=-1) a[x4][y4]=a[x1][y1]; else a[x1][y1]=a[x4][y4];
                        if (a[x2][y2]!=-1) a[x3][y3]=a[x2][y2]; else a[x2][y2]=a[x3][y3];
                    } else {
                        if (a[x1][y1]!=-1) a[x4][y4]=1-a[x1][y1]; else a[x1][y1]=1-a[x4][y4];
                        if (a[x2][y2]!=-1) a[x3][y3]=1-a[x2][y2]; else a[x2][y2]=1-a[x3][y3];
                    }
                    fnd=true; break;
                }
            }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) if (a[i][j]!=-1){
            for (int k=0;k<6;k++) if (check(i+flg[k][0],j+flg[k][1])){
                if (a[i+flg[k][0]][j+flg[k][1]]!=-1) continue;
                int f=query(i,j,i+flg[k][0],j+flg[k][1]);
                a[i+flg[k][0]][j+flg[k][1]]=(f)?a[i][j]:(1-a[i][j]);
            }
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) if (a[i][j]!=-1){
            for (int k=0;k<6;k++) if (check(i+flg[k][0],j+flg[k][1])){
                if (a[i+flg[k][0]][j+flg[k][1]]!=-1) continue;
                int f=query(i,j,i+flg[k][0],j+flg[k][1]);
                a[i+flg[k][0]][j+flg[k][1]]=(f)?a[i][j]:(1-a[i][j]);
            }
        }
    printf("!\n");
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) printf("%d",a[i][j]);
        printf("\n");
    }
    return 0;
}