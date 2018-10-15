#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10005;
int n,ans=0;
int main(){
    scanf("%d",&n);
    ans=2;
    for (int i=2;i<=n;i++) ans+=4*i-3;
    printf("%d\n",ans);
    return 0;
}