#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=1e9+3;
const int maxn=65,maxm=245,maxv=1005,maxk=35;
int n,m,v,K;
int p[maxn],s[maxn];

struct magic{
    int to,num,need[maxn];
};
magic a[maxm];

int g[maxn][maxk]; // g[i][j]: 药品 i 使用 j 次魔法得到，最小代价
int tmp[maxn][maxk]; // tmp[i][j]: 对于某种药品所需求的药品，前 i 种使用 j 次魔法得到，最小代价
int f[maxk][maxv]; // f[i][j]: 使用 i 次魔法，使用 j 元钱，最大利润

signed main(){
    n=read(); m=read(); v=read(); K=read();
    for (int i=1;i<=n;i++) p[i]=read(),s[i]=read();
    for (int i=1;i<=m;i++){
        a[i].to=read(), a[i].num=read();
        for (int j=1;j<=a[i].num;j++) a[i].need[j]=read();
    }

    for (int i=1;i<=n;i++)
        for (int j=0;j<=K;j++)
            g[i][j]=p[i];

    for (int ak=1;ak<=K;ak++){
        for (int i=1;i<=m;i++){
            for (int j=1;j<=a[i].num;j++){
                for (int k=0;k<=ak-1;k++){
                    tmp[j][k]=INF;
                    for (int t=0;t<=k;t++){
                        tmp[j][k]=min(tmp[j][k],tmp[j-1][k-t]+g[a[i].need[j]][t]);
                    }
                }
            }
            g[a[i].to][ak]=min(g[a[i].to][ak],tmp[a[i].num][ak-1]);
        }
    }

    for (int i=1;i<=n;i++)
        for (int j=0;j<=K;j++)
            for (int k=0;k<=K-j;k++)
                for (int t=0;t<=v-g[i][j];t++)
                    f[j+k][t+g[i][j]]=max(f[j+k][t+g[i][j]],f[k][t]+s[i]-g[i][j]);

    printf("%lld\n",f[K][v]);
    
    return 0;
}