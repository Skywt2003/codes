#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=100005;
int n,a[maxn],ans=0;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline int find(int x){
    int L=1,R=n,mid,ret=-1;
    while (L<=R){
        mid=((R-L)>>1)+L;
        if (a[mid]<x){
            ret=a[mid];L=mid+1;
        } else R=mid-1;
    }
    return ret;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=a[n]/a[i]+1;j++){
            int now=find(j*a[i]);if (now==-1||now<a[i]) continue;
            if (now%a[i]>ans) ans=now%a[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}