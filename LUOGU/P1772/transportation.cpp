#include<bits/stdc++.h>

using namespace std;
#define int long long

int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxd=105,maxn=25,maxm=505;

int d,n,m,s,cst,INF,dst[maxn][maxn],ndst[maxn][maxn],g[maxd][maxd],f[maxd];

bool vis[maxn][maxd],nowvis[maxn];


signed main(){
    memset(vis,1,sizeof(vis));
    memset(dst,63,sizeof(dst));INF=dst[0][0];

    d=read();n=read();cst=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),w=read();
        if (w<dst[x][y]) dst[x][y]=dst[y][x]=w;
    }

    s=read();
    for (int i=1;i<=s;i++){
        int p=read(),x=read(),y=read();
        for (int j=x;j<=y;j++) vis[p][j]=false;
    }

    for (int ii=1;ii<=d;ii++)
        for (int jj=ii;jj<=d;jj++){
            memset(nowvis,1,sizeof(nowvis));
            for (int j=1;j<=n;j++)
                for (int i=ii;i<=jj;i++)
                    if (vis[j][i]==false){nowvis[j]=false;break;}
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    ndst[i][j]=dst[i][j];
            for (int k=1;k<=n;k++) if (nowvis[k])
                for (int i=1;i<=n;i++) if (nowvis[i])
                    for (int j=1;j<=n;j++) if (nowvis[j]&&ndst[i][k]!=INF&&ndst[k][j]!=INF){
                        if (ndst[i][k]+ndst[k][j]<ndst[i][j])
                            ndst[i][j]=ndst[j][i]=ndst[i][k]+ndst[k][j];
        }
        g[ii][jj]=ndst[1][n];
    }

    memset(f,63,sizeof(f));f[0]=0;
    for (int i=1;i<=d;i++)
        for (int j=0;j<i;j++) if (g[j+1][i]!=INF)
            if (f[j]+cst+g[j+1][i]*(i-j)<f[i]) f[i]=f[j]+cst+g[j+1][i]*(i-j);
    
    printf("%lld\n",f[d]-cst);
    return 0;
}