#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,m,a[maxn],lst[maxn];
long long ans=-1;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline bool check(long long x){
    for (int i=1;i<=n;i++) lst[i]=a[i];
    int j=1;
    for (int i=1;i<=m;i++){
        long long now=x-(long long)j; // First, let the student walk to the j-th pile.
        if (now<=0) continue;
        while (now>(long long)lst[j]&&j<=n){now-=(long long)lst[j];j++;now--;}
        lst[j]-=now; // Let the student stay.
        if (lst[j]<=0) j++;
        if (j>n) return true;
    }
    for (int i=j;i<=n;i++) if (lst[i]) return false;
    return true;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) a[i]=read();
    long long L=2,R=(long long)1<<60;
    while (L<=R){
        long long mid=((R-L)>>1)+L;
        if (check(mid)){
            ans=mid;
            R=mid-1;
        } else L=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}