#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=55;
int n;
long long f[maxn];
int main(){
    scanf("%d",&n);
    f[1]=1;f[2]=2;
    for (int i=3;i<=n;i++) f[i]=f[i-1]+f[i-2];
    printf("%lld\n",f[n]);
    return 0;
}