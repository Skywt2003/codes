#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005,tt=1000000007;
int n,k,f[maxn][maxn];
int main(){
    scanf("%d%d",&n,&k);
    f[1][1]=1;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=k;j++) if (i!=1||j!=1) f[i][j]=(f[i-1][j-1]+((long long)(i-1)*(f[i-1][j]))%tt)%tt;
    printf("%d\n",f[n][k]);
    return 0;
}