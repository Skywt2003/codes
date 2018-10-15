#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=55;
int n,a[maxn];
inline int myabs(int x){
    if (x<0) return -x; else return x;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int ans=0;
    for (int i=3;i<n;i+=2) if (myabs(a[i]-a[i-2])>ans) ans=myabs(a[i]-a[i-2]);
    for (int i=4;i<n;i+=2) if (myabs(a[i]-a[i-2])>ans) ans=myabs(a[i]-a[i-2]);
    if (myabs(a[2]-a[1])>ans) ans=myabs(a[2]-a[1]);
    if (myabs(a[n]-a[n-1])>ans) ans=myabs(a[n]-a[n-1]);
    if (myabs(a[n]-a[n-2])>ans) ans=myabs(a[n]-a[n-2]);
    printf("%d\n",ans);
    return 0;
}