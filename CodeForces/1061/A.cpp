#include<bits/stdc++.h>

using namespace std;
#define int long long

const int maxn=100005;


inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int n,s;

signed main(){
    n=read();s=read();
    int ans=0;
    for (int i=n;i>=1;i--){
        ans=ans+s/i;
        s-=i*(s/i);
    }
    printf("%lld\n",ans);
    return 0;
}