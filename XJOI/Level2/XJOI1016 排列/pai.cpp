#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10;
int n,a[maxn];
bool ctn=true;
inline void next(){
    int j=n;
    while (a[j-1]>a[j]&&j-1>=1) j--;
    if (j==1){ctn=false;return;}
    j--;int minsub=1<<30;int k=-1;
    for (int i=j+1;i<=n;i++) if (a[i]>a[j]&&a[i]-a[j]<minsub){minsub=a[i]-a[j];k=i;}
    if (k==-1){ctn=false;return;}
    swap(a[k],a[j]);
    sort(a+j+1,a+n+1);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) a[i]=i;
    while (ctn){
        for (int i=1;i<=n;i++) printf("%d ",a[i]);
        printf("\n");
        next();
    }
    return 0;
}