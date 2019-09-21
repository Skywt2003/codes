#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int n,k;
int ans=0;

signed main(){
    n=read();k=read();
    ans=n*k;

    for (int l=1,r;l<=n;l=r+1){
        if (k/l) r=min(n,k/(k/l)); else r=n;
        ans-=(k/l)*(l+r)*(r-l+1)/2;
        if (r==n) break;
    }

    printf("%lld\n",ans);
    return 0;
}