#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=25;
int n,m;
long long f[maxn][maxn];
int main(){
    scanf("%d%d",&m,&n);
    for (int i=1;i<=m;i++) f[1][i]=1;
    for (int i=2;i<=n;i++)
    for (int j=i;j<=m-n+i;j++)
    for (int k=i-1;k<=m-n+i-1;k++) if (j-k>=1) f[i][j]+=f[i-1][k];
    printf("%lld\n",f[n][m]);
    return 0;
}