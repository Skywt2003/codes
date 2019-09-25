#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=105,maxm=5,maxk=15;

int n,m,k;
int a[maxn][maxm];

int f[maxn][maxn][maxk];
int sum[maxn][5];

signed main(){
    n=read();m=read();k=read();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            a[i][j]=read();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=2;j++)
            sum[i][j]=sum[i-1][j]+a[i][j];

    memset(f,0x80,sizeof(f));
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            f[i][j][0]=0;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            for (int t=1;t<=k;t++){
                f[i][j][t]=max(f[i-1][j][t],f[i][j-1][t]);
                for (int l=0;l<i;l++) f[i][j][t]=max(f[i][j][t],f[l][j][t-1]+sum[i][1]-sum[l][1]);
                for (int l=0;l<j;l++) f[i][j][t]=max(f[i][j][t],f[i][l][t-1]+sum[j][2]-sum[l][2]);
                if (i==j){
                    for (int l=0;l<i;l++) f[i][j][t]=max(f[i][j][t],f[l][l][t-1]+sum[i][1]+sum[j][2]-sum[l][1]-sum[l][2]);
                }
            }

    printf("%lld\n",f[n][n][k]);

    return 0;
}