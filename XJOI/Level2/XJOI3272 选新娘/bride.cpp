#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=25;
int n,m;
long long f[maxn][maxn],c[maxn];
int main(){
    scanf("%d%d",&n,&m);
    f[1][0]=f[1][1]=1;
    for (int i=2;i<=n;i++)
    for (int j=0;j<=m;j++){
        if (j) f[i][j]+=f[i-1][j]+f[i-1][j-1]; else f[i][j]+=f[i-1][j];
    }
    c[1]=0;c[2]=1;
    for (int i=3;i<=m;i++) c[i]=(long long)(i-1)*(c[i-1]+c[i-2]);
    printf("%lld\n",c[m]*f[n][m]);
    return 0;
}