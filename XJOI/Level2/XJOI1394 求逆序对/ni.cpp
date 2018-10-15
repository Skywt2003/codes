#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,a[maxn],c[maxn];
long long ans=0;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void msort(int L,int R){
    if (L>=R) return;
    int mid=((R-L)>>1)+L;
    msort(L,mid);msort(mid+1,R);
    int i=L,j=mid+1;
    for (int k=L;k<=R;k++){
        if (i<=mid&&(a[i]<=a[j]||j>R)) c[k]=a[i++]; else {c[k]=a[j++];ans+=(long long)mid-i+1;}
    }
    for (int k=L;k<=R;k++) a[k]=c[k];
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    msort(1,n);
    printf("%lld\n",ans);
    return 0;
}