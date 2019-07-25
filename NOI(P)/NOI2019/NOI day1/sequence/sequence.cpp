#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=35;
int T,n,K,L,a[maxn],b[maxn];
int f[maxn][maxn][maxn][maxn];

signed main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    T=read();
    while (T--){
        n=read();K=read(),L=read();
        for (int i=1;i<=n;i++) a[i]=read();
        for (int i=1;i<=n;i++) b[i]=read();

        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        for (int j=0;j<=K;j++)
        for (int k=0;k<=K;k++)
        for (int t=0;t<=K;t++){
            f[i][j][k][t]=f[i-1][j][k][t];
            if (j-1>=0) f[i][j][k][t]=max(f[i][j][k][t],f[i-1][j-1][k][t]+a[i]);
            if (k-1>=0) f[i][j][k][t]=max(f[i][j][k][t],f[i-1][j][k-1][t]+b[i]);
            if (j-1>=0 && k-1>=0 && t-1>=0) f[i][j][k][t]=max(f[i][j][k][t],f[i-1][j-1][k-1][t-1]+a[i]+b[i]);
        }
        
        int ans=0;
        for (int i=L;i<=K;i++) ans=max(ans,f[n][K][K][i]);
        printf("%lld\n",ans);
    }
    return 0;
}