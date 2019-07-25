#include<bits/stdc++.h>
// #define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=2005,maxv=305,maxe=90005;
const double inf=1e10;
const int INF=1<<29;
int n,m,v,e,c[maxn],d[maxn];
int dist[maxv][maxv];
double p[maxn],f[maxn][maxn][2];

void Floyd(){
    for (int k=1;k<=v;k++)
    for (int i=1;i<=v;i++) if (k!=i)
    for (int j=1;j<=v;j++) if (k!=j && i!=j)
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

signed main(){

    n=read();m=read();v=read();e=read();
    for (int i=1;i<=n;i++)
        for (int j=0;j<=m;j++)
            f[i][j][0]=f[i][j][1]=inf;
    for (int i=1;i<=v;i++)
        for (int j=1;j<=v;j++)
            dist[i][j]=dist[j][i]=((i==j)?0:INF);
    for (int i=1;i<=n;i++) c[i]=read();
    for (int i=1;i<=n;i++) d[i]=read();
    for (int i=1;i<=n;i++) scanf("%lf",&p[i]);
    for (int i=1;i<=e;i++){
        int x=read(),y=read(),z=read();
        dist[x][y]=dist[y][x]=min(dist[x][y],z);
    }

    Floyd();

    f[1][0][0]=f[1][1][1]=0.0;
    for (int i=2;i<=n;i++)
    for (int j=0;j<=min(n,m);j++){
        f[i][j][0]=min(f[i-1][j][0]+dist[c[i-1]][c[i]],
                       (1.0-p[i-1])*(f[i-1][j][1]+dist[c[i-1]][c[i]]) + p[i-1]*(f[i-1][j][1]+dist[d[i-1]][c[i]]));
        if (j==0) continue;
        double lastToCi=(1.0-p[i-1])*(f[i-1][j-1][1]+dist[c[i-1]][c[i]]) + p[i-1]*(f[i-1][j-1][1]+dist[d[i-1]][c[i]]);
        double lastToDi=(1.0-p[i-1])*(f[i-1][j-1][1]+dist[c[i-1]][d[i]]) + p[i-1]*(f[i-1][j-1][1]+dist[d[i-1]][d[i]]);
        f[i][j][1]=min((1.0-p[i])*(f[i-1][j-1][0]+dist[c[i-1]][c[i]]) + p[i]*(f[i-1][j-1][0]+dist[c[i-1]][d[i]]),
                       (1.0-p[i])*(lastToCi) + p[i]*(lastToDi));
    }
    double ans=f[n][0][0];
    for (int i=1;i<=m;i++) ans=min(ans,min(f[n][i][0],f[n][i][1]));
    printf("%.2lf\n",ans);
    return 0;
}