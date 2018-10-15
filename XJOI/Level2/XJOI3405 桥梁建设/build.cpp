#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=5005,tt=998244353;
int a,b,c,f[maxn][maxn];
inline int max3(int x,int y,int z){
    int ret=x;
    if (y>ret) ret=y;
    if (z>ret) ret=z;
    return ret;
}
inline int get(int n,int m){
    if (n>m) swap(n,m);
    for (int i=0;i<=n;i++) f[i][0]=1;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=min(n,m);j++) f[i][j]=(f[i-1][j]+((long long)f[i-1][j-1]*(m-j+1))%tt)%tt;
    int sum=0;
    for (int i=0;i<=min(n,m);i++) sum=(sum+f[n][i])%tt;
    return sum;
}
int main(){
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",(long long)((long long)get(a,b)*get(b,c)%tt)*get(a,c)%tt);
    return 0;
}