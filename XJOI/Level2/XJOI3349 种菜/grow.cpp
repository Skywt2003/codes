#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=5005;
int n,m,a[maxn],f[maxn],ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
    for (int j=0;j<i;j++) if (a[j]<=a[i]) f[i]=max(f[i],f[j]+1);
    for (int i=1;i<=n;i++) if (f[i]>ans) ans=f[i];
    printf("%d\n",n-ans);
    return 0;
}