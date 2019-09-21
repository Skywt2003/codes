#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1000005,tt=998244353;

int n,m;
int a[maxn];

signed main(){
    n=read(); m=read();

    int sum=1;
    a[1]=1;
    for (int i=2;i<m;i++) a[i]=a[i-1]*2%tt,sum=(sum+a[i])%tt;
    a[m]=(a[m-1]*2%tt-1+tt)%tt,sum=(sum+a[m])%tt;
    
    for (int i=m+1;i<=n;i++){
        a[i]=sum;
        sum=(sum+a[i]-a[i-m]+tt)%tt;
    }

    printf("%lld\n",a[n]);
    return 0;
}