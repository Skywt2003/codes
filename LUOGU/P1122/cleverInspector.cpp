#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int maxn=200005;

int n,m,s;
int w[maxn],v[maxn];
pair<int,int> itv[maxn];
int ans=INF;
int sum[maxn],num[maxn];

int check(int x){
    for (int i=1;i<=n;i++)
        num[i]=num[i-1]+(w[i]>x),
        sum[i]=sum[i-1]+(w[i]>x)*v[i];
    int ret=0;
    for (int i=1;i<=m;i++) ret+=(num[itv[i].second]-num[itv[i].first-1]) * (sum[itv[i].second]-sum[itv[i].first-1]);
    return ret;
}

int L,R;
#define mid (((R-L)>>1)+L)

signed main(){
    n=read(); m=read(); s=read();
    for (int i=1;i<=n;i++) w[i]=read(),v[i]=read();
    for (int i=1;i<=m;i++) itv[i].first=read(),itv[i].second=read();

    L=0,R=1e6;
    while (L<=R){
        int now=check(mid);
        if (now>s) L=mid+1; else
        ans=min(ans,s-now),R=mid-1;
    }

    L=0,R=1e6;
    while (L<=R){
        int now=check(mid);
        if (now<s) R=mid-1; else
        ans=min(ans,now-s),L=mid+1;
    }

    printf("%lld\n",ans);
    return 0;
}