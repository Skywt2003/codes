#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=35;
int n;
long long f[maxn][4];
int main(){
    f[1][0]=f[1][1]=f[1][2]=f[1][3]=1;
    scanf("%d",&n);
    for (int i=2;i<=n;i++)
    for (int j=0;j<=3;j++)
    for (int k=0;k<=3;k++) if (j||k) f[i][j]+=f[i-1][k];
    printf("%lld\n",f[n][0]+f[n][1]+f[n][2]+f[n][3]);
    return 0;
}