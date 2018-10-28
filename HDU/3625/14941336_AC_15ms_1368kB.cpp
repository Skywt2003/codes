#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=25;
int T,n,m;
long long f[maxn][maxn],fac[maxn];
inline void BuildFact(){
    fac[0]=1;
    for (int i=1;i<=20;i++) fac[i]=fac[i-1]*i;
}
inline void BuildStirlingNumber(){
    f[1][1]=1;
    for (int i=2;i<=20;i++)
        for (int j=1;j<=i;j++)
            f[i][j]=f[i-1][j-1]+(i-1)*f[i-1][j];
}
int main(){
    BuildFact();
    BuildStirlingNumber();
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        long long now=0;
        for (int i=1;i<=m;i++) now=now+f[n][i]-f[n-1][i-1];
        printf("%.4f\n",(double)now/(double)fac[n]);
    }
    return 0;
}
