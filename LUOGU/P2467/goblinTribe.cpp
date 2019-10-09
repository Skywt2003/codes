#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=4205;

int n,tt;
int f[2][maxn];

signed main(){
    n=read(); tt=read();
    f[2&1][2]=1;
    for (int i=3;i<=n;i++)
        for (int j=2;j<=i;j++)
            f[i&1][j]=(f[i&1][j-1]+f[i&1^1][i-j+1])%tt;
    int ans=0;
    for (int i=2;i<=n;i++) ans=(ans+f[n&1][i])%tt;
    printf("%lld\n",ans*2%tt);
    return 0;
}