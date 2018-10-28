#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=25;
int T,n,m;
long long f[maxn][maxn],c[maxn];
int main(){
    scanf("%d",&T);
    f[1][0]=f[1][1]=1;
    for (int i=2;i<=20;i++)
    for (int j=0;j<=20;j++){
        if (j) f[i][j]+=f[i-1][j]+f[i-1][j-1]; else f[i][j]+=f[i-1][j];
    }
    c[1]=0;c[2]=1;
    for (int i=3;i<=20;i++) c[i]=(long long)(i-1)*(c[i-1]+c[i-2]);
    while (T--){
        scanf("%d%d",&n,&m);
        printf("%lld\n",c[m]*f[n][m]);
    }
    return 0;
}
