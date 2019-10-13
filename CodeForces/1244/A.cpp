#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int T;
int n,m,a,b,k;

signed main(){
    T=read();
    while (T--){
        n=read(); m=read(); a=read(); b=read(); k=read();
        if ((n+a-1)/a + (m+b-1)/b <= k) printf("%lld %lld\n",(n+a-1)/a , (m+b-1)/b); else printf("-1\n");
    }
    return 0;
}