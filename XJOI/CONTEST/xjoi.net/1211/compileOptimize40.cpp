#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=3005,INF=1e9;
int n,m,a[maxn];
int f[maxn][maxn][2];
int g[maxn][2];

signed main(){
    n=read();m=read();
    if ((n>>1)<m){
        printf("Error!\n");
        return 0;
    }
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=n;i++)
        for (int j=0;j<=m;j++) f[i][j][0]=f[i][j][1]=g[j][0]=g[j][1]=-INF;
    f[1][0][0]=0;
    f[1][1][1]=a[1];
    for (int i=2;i<=n;i++){
        for (int j=min((i+1)>>1,m);j>=0;j--){
            if (j-1>=0 && g[j-1][0]!=INF) f[i][j][0]=g[j-1][0]+a[i];
            if (j-2>=0 && g[j-1][1]!=INF) f[i][j][1]=g[j-1][1]+a[i];
            g[j][0]=max(g[j][0],f[i-1][j][0]);
            g[j][1]=max(g[j][1],f[i-1][j][1]);
        }
    }
    int ans=f[n][m][0];
    for (int i=m*2-1;i<n;i++) ans=max(ans,max(f[i][m][0],f[i][m][1]));
    for (int i=m*2-1;i<n-1;i++) ans=max(ans,f[i][m-1][0]+a[n]);
    if (ans==-INF) printf("Error!\n"); else printf("%lld\n",ans);
    return 0;
}