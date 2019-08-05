#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=(int)1<<60;
const int maxn=300005;
int n,m,h[maxn],p;

signed main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) h[i]=read();
    for (int i=1;i<=m;i++){
        p=read();
        int ans=INF;
        for (int i=1;i<=n;i++) ans=min(ans,p*i+h[i]);
        printf("%lld\n",ans);
    }
    return 0;
}