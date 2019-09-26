#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005,maxs=305,maxk=20,stdz=8;

int T;
int n;
int a[maxn],b[maxn];
int f[maxn][maxs][maxk];
int INF;

void init(){
    memset(f,63,sizeof(f));
    INF=f[0][0][0];
}

signed main(){
    T=read();
    while (T--){
        init();
        n=read();
        for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();

        f[1][0][stdz-1]=0;
        for (int i=1;i<=n;i++)
            for (int j=0;j<(1<<8);j++)
                for (int k=-8;k<=7;k++) if (f[i][j][k+stdz]!=INF){
                    if (j&1) f[i+1][j>>1][k-1+stdz]=min(f[i+1][j>>1][k-1+stdz],f[i][j][k+stdz]); else {
                        int r=INF;
                        for (int t=0;t<=7;t++) if ((j&(1<<t)) == 0){
                            if (i+t > r) break;
                            r=min(r,i+t+b[i+t]);
                            f[i][j|(1<<t)][t+stdz]=min(f[i][j|(1<<t)][t+stdz],f[i][j][k+stdz]+((i+k)?(a[i+k]^a[i+t]):0));
                        }
                    }
                }

        int ans=INF;
        for (int k=-8;k<=0;k++) ans=min(ans,f[n+1][0][k+stdz]);
        printf("%lld\n",ans);
    }
    return 0;
}