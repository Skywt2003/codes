#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int n,m,k1,k2,x;

signed main(){
    n=read(); m=read();
    k1=read(); k2=read();
    x=read();

    int xx=x;
    xx-=n*(k1-1)+m*(k2-1);
    if (xx<=0) printf("%lld ",(int)0); else printf("%lld ",xx);

    xx=x;int ans=0;
    if (k1<k2){
        ans+=min(xx/k1,n);xx-=min(xx/k1,n)*k1;
        ans+=min(xx/k2,m);xx-=min(xx/k2,m)*k2;
    } else {
        ans+=min(xx/k2,m);xx-=min(xx/k2,m)*k2;
        ans+=min(xx/k1,n);xx-=min(xx/k1,n)*k1;
    }
    printf("%lld\n",ans);
    return 0;
}