#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
#define int long long

const int maxn=1005;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int n,s,sum=0,ans=-1,minnum=(int)1<<60,a[maxn];

inline bool check(int x){
    int now=0;
    for (int i=1;i<=n;i++) now+=(a[i]>x)?(a[i]-x):0;
    return now>=s;
}

signed main(){
    n=read();s=read();
    for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i],minnum=min(minnum,a[i]);
    if (sum<s){
        printf("-1\n");
        return 0;
    }
    int L=0,R=minnum;
    while (L<=R){
        int mid=((R-L)>>(int)1)+L;
        if (check(mid)) ans=mid,L=mid+1; else R=mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}