#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005;

int n,a[maxn];
int f[maxn][2];

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();

    f[1][0]=f[1][1]=1;
    for (int i=2;i<=n;i++){
        if (a[i]>a[i-1]) f[i][1]=f[i-1][0]+1; else f[i][1]=f[i-1][1];
        if (a[i]<a[i-1]) f[i][0]=f[i-1][1]+1; else f[i][0]=f[i-1][0];
    }

    printf("%lld\n",max(f[n][0],f[n][1]));
    return 0;
}