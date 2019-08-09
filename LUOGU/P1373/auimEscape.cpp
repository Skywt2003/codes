#include<bits/stdc++.h>
// #define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=805,maxk=20;
const int step[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
const int tt=1000000007;

int n,m,K,a[maxn][maxn];
int f[maxn][maxn][maxk];

#define check(x,y) (!(x<1||y<1||x>n||y>m))

#define lx (x+step[i][0])
#define ly (y+step[i][1])
#define nx (x+step[j][0])
#define ny (y+step[j][1])

signed main(){
    n=read();m=read();K=read();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            a[i][j]=read();

    for (int x=1;x<=n;x++)
        for (int y=1;y<=m;y++)
            for (int k=0;k<K+1;k++)
                for (int i=0;i<2;i++)
                    for (int j=2;j<4;j++) if (check(nx,ny)){
                        int nxt=(k+a[x][y]-a[nx][ny]+(K+1))%(K+1);
                        f[nx][ny][nxt]=(f[nx][ny][nxt]+f[lx][ly][k]+(i==0 && k==0))%tt;
                    }

    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            ans=(ans+f[i][j][0])%tt;

    printf("%d\n",ans);
    return 0;
}