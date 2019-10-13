#include<bits/stdc++.h>
// #define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005;

int ans=0;
int n,a[maxn];

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=2;i<=n+1;i++) ans+=max(0,a[i-1]-a[i]);
    printf("%d\n",ans);
    return 0;
}