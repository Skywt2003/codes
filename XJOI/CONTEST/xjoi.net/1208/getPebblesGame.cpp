#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005;

int T,n,a[maxn];

signed main(){
    T=read();
    while (T--){
        n=read();
        for (int i=1;i<=n;i++) a[i]=read();
        int ans=0;
        for (int i=n;i>=1;i--) if ((n-i+1)&1) ans^=(a[i]-a[i-1]);
        printf(ans?"TAK\n":"NIE\n");
    }
    return 0;
}