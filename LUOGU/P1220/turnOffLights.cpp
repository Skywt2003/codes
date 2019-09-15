#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=55;

int n,s,INF;
int f[maxn][maxn][2];
int g[maxn][maxn];
int sum[maxn];

struct light{
    int x,y;
};
light a[maxn];

signed main(){
    n=read(); s=read();
    for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),sum[i]=sum[i-1]+a[i].y;

    for (int i=1;i<=n;i++)
    for (int j=i;j<=n;j++)
        g[i][j]=sum[i-1]+sum[n]-sum[j];

    memset(f,63,sizeof(f)); INF=f[0][0][0];
    f[s][s][0]=f[s][s][1]=0;
    for (int L=0;L<=n-2;L++)
    for (int i=1;i<=n-L;i++){
        int j=i+L;
        f[i][j][0]=min(f[i][j][0],f[i][j][1]+g[i][j]*(a[j].x-a[i].x));
        f[i][j][1]=min(f[i][j][1],f[i][j][0]+g[i][j]*(a[j].x-a[i].x));
        if (f[i][j][0]<INF){
            f[i-1][j][0]=min(f[i-1][j][0],f[i][j][0]+g[i][j]*(a[i].x-a[i-1].x));
            f[i][j+1][1]=min(f[i][j+1][1],f[i][j][0]+g[i][j]*(a[j+1].x-a[i].x));
        }
        if (f[i][j][1]<INF){
            f[i-1][j][0]=min(f[i-1][j][0],f[i][j][1]+g[i][j]*(a[j].x-a[i-1].x));
            f[i][j+1][1]=min(f[i][j+1][1],f[i][j][1]+g[i][j]*(a[j+1].x-a[j].x));
        }
    }
    printf("%lld\n",min(f[1][n][0],f[1][n][1]));
    return 0;
}