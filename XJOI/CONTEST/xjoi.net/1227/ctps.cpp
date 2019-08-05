#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=30005;
int n,m;
double a[maxn],b[maxn],c[maxn],d[maxn];

signed main(){
    n=read();
    for (int i=1;i<=n;i++) scanf("%lf%lf%lf%lf",&a[i],&b[i],&c[i],&d[i]);
    m=read();
    for (int i=1;i<=m;i++){
        double aa,bb,cc,dd;
        scanf("%lf%lf%lf%lf",&aa,&bb,&cc,&dd);
        int ans=0;
        for (int i=1;i<=n;i++) if (a[i]<=aa && b[i]<=bb && c[i]<=cc && d[i]<=dd) ans++;
        printf("%lld\n",ans);
    }
    return 0;
}