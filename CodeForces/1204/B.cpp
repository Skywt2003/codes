#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f;

const int maxn=1005;

int n,l,r;

int a[maxn];
int ans=0;

signed main(){
    n=read(); l=read(); r=read();
    
    a[1]=1;
    for (int i=2;i<=l;i++) a[i]=a[i-1]*2;
    for (int i=l+1;i<=n;i++) a[i]=1;
    ans=0;
    for (int i=1;i<=n;i++) ans+=a[i];
    printf("%d ",ans);

    a[1]=1;
    for (int i=2;i<=r;i++) a[i]=a[i-1]*2;
    for (int i=r+1;i<=n;i++) a[i]=a[r];
    ans=0;
    for (int i=1;i<=n;i++) ans+=a[i];
    printf("%d\n",ans);
    return 0;
}