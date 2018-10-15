#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=85;
int n;
long long f[maxn];
int main(){
    scanf("%d",&n);
    f[0]=1;f[1]=1;
    for (int i=2;i<=n;i++) f[i]=(long long)f[i-1]+(long long)f[i-2];
    printf("%lld\n",f[n]);
    return 0;
}