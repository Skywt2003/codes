#include<bits/stdc++.h>
using namespace std;

// #define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int tt=1e9+7;
const int maxn=24+5,maxs=16777216+5;

int n,alls,a[maxn];
int m,b[2];

int f[maxs],sum[maxs];

int lowbit(int x){
    return x&(-x);
}

signed main(){
    n=read(); for (int i=0;i<n;i++) a[i]=sum[1<<i]=read(); alls=1<<n;
    memset(b,-1,sizeof(b));
    m=read(); for (int i=0;i<m;i++) b[i]=read();

    f[0]=1;
    for (int i=1,now=1;i<alls;i++,now=i){
        for (int j=lowbit(now);now;now^=j,j=lowbit(now)) sum[i]=sum[i^j]+sum[j],f[i]=((long long)f[i]+f[i^j])%tt;
        if (sum[i]==b[0] || sum[i]==b[1]) f[i]=0;
    }

    printf("%d\n",f[alls-1]);
    return 0;
}