#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int tt=100000007;
const int maxn=2005,N=2000;

int T;
int f[maxn];

signed main(){
    f[0]=1;
    for (int i=2;i<=N;i++)
        for (int j=i;j<=N;j++)
            f[j]=(f[j]+f[j-i])%tt;

    T=read();
    while (T--) printf("%lld\n",f[read()]);
    return 0;
}