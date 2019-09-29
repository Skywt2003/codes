#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1000005;

int n,m,a[maxn],sum[maxn];

struct node{
    int x,s,t;
};
node q[maxn];

bool check(int now){
    memset(sum,0,sizeof(sum));
    for (int i=1;i<=now;i++) sum[q[i].s]+=q[i].x,sum[q[i].t+1]-=q[i].x;
    for (int i=1;i<=n;i++){
        sum[i]=sum[i-1]+sum[i];
        if (sum[i] > a[i]) return false;
    }
    return true;
}

int L,R,ans=0;

#define mid (((R-L)>>1)+L)

signed main(){
    n=read(); m=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=m;i++) q[i].x=read(),q[i].s=read(),q[i].t=read();

    L=1,R=m;
    while (L<=R){
        if (check(mid)) ans=mid,L=mid+1; else R=mid-1;
    }
    
    if (ans==m) printf("0\n"); else printf("-1\n%lld\n",ans+1);
    return 0;
}