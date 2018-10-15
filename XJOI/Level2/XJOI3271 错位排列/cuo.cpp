#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=25;
int n;
long long a[maxn];
int main(){
    scanf("%d",&n);
    a[1]=0;a[2]=1;
    for (int i=3;i<=n;i++) a[i]=(long long)(i-1)*(long long)(a[i-1]+a[i-2]);
    printf("%lld\n",a[n]);
    return 0;
}