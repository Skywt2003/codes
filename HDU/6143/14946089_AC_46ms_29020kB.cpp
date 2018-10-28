#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=2005,tt=1e9+7;
int T,n,m,c[maxn][maxn],fac[maxn],f[maxn][maxn];
inline void Build(){
    for (int i=0;i<=2000;i++) c[i][0]=1;
    for (int i=1;i<=2000;i++){
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%tt;
    }
    for (int i=1;i<=2000;i++) f[i][1]=1;
    for (int i=2;i<=2000;i++)
        for (int j=1;j<=i;j++)
            f[i][j]=(f[i-1][j-1]+(long long)f[i-1][j]*j%tt)%tt;
    fac[0]=1;
    for (int i=1;i<=2000;i++) fac[i]=(long long)fac[i-1]*i%tt;
}
inline int qsm(int a,int b){
    int ret=1,w=a;
    while (b){
        if (b&1) ret=(long long)ret*w%tt;
        b>>=1;w=(long long)w*w%tt;
    }
    return ret;
}
int main(){
    scanf("%d",&T);
    Build();
    while (T--){
        scanf("%d%d",&n,&m);
        int ans=0;
        for (int i=1;i<m;i++) ans=((long long)ans+(long long)c[m][i]%tt*fac[i]%tt*f[n][i]%tt*qsm(m-i,n)%tt)%tt;
        printf("%d\n",ans);
    }
    return 0;
}
