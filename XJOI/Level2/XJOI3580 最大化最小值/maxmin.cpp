#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,m,a[maxn],ans=0;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline bool check(int x){
    int cnt=1,i=1,j;
    while (cnt<m){
        j=i+1;
        while (a[j]-a[i]<x&&j+1<=n) j++;
        if (a[j]-a[i]<x) return false;
        cnt++;i=j;
    }
    return true;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    int L=1,R=a[n];
    while (L<=R){
        int mid=((R-L)>>1)+L;
        if (check(mid)){
            ans=mid;L=mid+1;
        } else R=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}