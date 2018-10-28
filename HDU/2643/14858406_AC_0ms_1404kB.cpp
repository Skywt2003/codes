#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105,tt=20090126;
int T,n,f[maxn][maxn];
inline int js(int x){
    int ret=1;
    for (int i=2;i<=x;i++) ret=(ret*i)%tt;
    return ret;
}
int main(){
    scanf("%d",&T);
    f[1][1]=1;
    for (int i=1;i<=100;i++)
        for (int j=1;j<=i;j++) if (i!=1||j!=1)
            f[i][j]=(f[i-1][j-1]+((long long)j*f[i-1][j])%tt)%tt;
    while (T--){
        scanf("%d",&n);
        int sum=0;
        for (int i=1;i<=n;i++) sum=(sum+((long long)f[n][i]*js(i))%tt)%tt;
        printf("%d\n",sum);
    }
    return 0;
}
