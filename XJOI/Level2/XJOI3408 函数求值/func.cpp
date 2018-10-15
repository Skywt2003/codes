#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,a[maxn];
long long ans=0,hsh[maxn],cnt[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    n=read();
    int maxnum=0;
    for (int i=1;i<=n;i++) a[i]=read();
    long long sum=0,alc=0;
    for (int i=1;i<=n;i++){
        ans+=(long long)(alc-cnt[a[i]]-cnt[a[i]-1]-cnt[a[i]+1])*a[i]-(long long)(sum-hsh[a[i]]-hsh[a[i]-1]-hsh[a[i]+1]);
        hsh[a[i]]+=a[i];cnt[a[i]]++;
        sum+=a[i];alc++;
    }
    printf("%lld\n",ans);
    return 0;
}