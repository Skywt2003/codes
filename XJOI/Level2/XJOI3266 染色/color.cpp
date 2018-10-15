#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=55;
int n;
long long f[maxn][3][3];
int main(){
    scanf("%d",&n);
    f[1][0][0]=f[1][1][1]=f[1][2][2]=1;
    for (int i=2;i<=n;i++)
    for (int j=0;j<=2;j++)
    for (int k=0;k<=2;k++) if (j!=k)
    for (int t=0;t<=2;t++) if ((i!=2&&i!=3)||(i==2&&k==t)||(i==3&&k!=t)) f[i][j][t]+=(long long)f[i-1][k][t];
    long long ans=0;
    for (int i=0;i<=2;i++)
    for (int j=0;j<=2;j++) if (i!=j) ans+=(long long)f[n][i][j];
    printf("%lld\n",ans);
    return 0;
}