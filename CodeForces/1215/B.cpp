#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=200005;

int n,a[maxn];
int f[maxn][2];

signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        int x=read();
        a[i]=((x<0)?(-1):(1));
    }
    for (int i=1;i<=n;i++) if (a[i]==1){
        f[i][0]=f[i-1][0];
        f[i][1]=f[i-1][1]+1;
    } else {
        f[i][0]=f[i-1][1]+1;
        f[i][1]=f[i-1][0];
    }
    int ans1=0,ans2=0;
    for (int i=1;i<=n;i++){
        // printf(": %lld %lld\n",f[i][0],f[i][1]);
        ans1+=f[i][0],ans2+=f[i][1];
    }
    printf("%lld %lld\n",ans1,ans2);
    return 0;
}