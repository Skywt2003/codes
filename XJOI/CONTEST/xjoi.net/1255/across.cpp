// XJOI 1255 B: ACROSS

#include <bits/stdc++.h>

using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int tt=998244353;

const int maxn=506,maxm=506;

int n,m;
int to[maxn];

int f[maxn][maxm];

signed main(){
    n=read(); m=read();
    for (int i=0;i<=n;i++) to[i]=read();

    for (int i=0;i<=n;i++){
        memset(f,0,sizeof(f));
        f[i][0]=1;
        for (int j=0;j<m;j++)
            for (int k=0;k<=n;k++) if (f[k][j]){
                f[to[k]][j+1]=(f[to[k]][j+1]+f[k][j])%tt;
                f[0][j+1]=(f[0][j+1]+f[k][j])%tt;
            }
        printf("%lld ",f[i][m]);
    }
    printf("\n");
    return 0;
}
