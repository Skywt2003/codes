#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=55,maxe=20005;
int n,m,dist[maxn][maxn];
bool g[maxn][maxn][32];

void build_g(){
    for (int t=1;t<=30;t++){
        for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) if (i!=j && !g[i][j][t])
            g[i][j][t]|=g[i][k][t-1] && g[k][j][t-1];
    }
}

void Floyd(){
    for (int k=1;k<=n;k++)
    for (int i=1;i<=n;i++) if (i!=k)
    for (int j=1;j<=n;j++) if (j!=k && i!=j)
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

signed main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        g[x][y][0]=true;
    }
    build_g();
    memset(dist,63,sizeof(dist));
    for (int i=1;i<=n;i++) dist[i][i]=0;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) if (i!=j)
    for (int k=0;k<=30;k++)
        if (g[i][j][k]) {dist[i][j]=1;break;}
    
    Floyd();
    printf("%lld\n",dist[1][n]);
    return 0;
}