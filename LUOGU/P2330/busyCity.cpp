#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=305,maxe=100005;

int n,e,ans=-1;

struct edge{
    int x,y,w;
};
edge a[maxe];

#define mid (((R-L)>>1)+L)

int fa[maxn];

void init(int n){
    for (int i=1;i<=n;i++) fa[i]=i;
}

int getfa(int x){
    if (fa[x]==x) return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}

bool Kruscal(int x){
    init(n); int cnt=0;
    for (int i=1;i<=e;i++) if (a[i].w <= x){
        int fx=getfa(a[i].x),fy=getfa(a[i].y);
        if (fx==fy) continue;
        cnt++; fa[fx]=fy;
        if (cnt==n-1) return true;
    }
    return false;
}

bool compare_w(edge aa,edge bb){
    return aa.w<bb.w;
}

signed main(){
    n=read();e=read();
    for (int i=1;i<=e;i++) a[i].x=read(),a[i].y=read(),a[i].w=read();

    sort(a+1,a+1+e,compare_w);

    int L=0,R=10000;
    while (L<=R){
        if (Kruscal(mid)) ans=mid,R=mid-1; else L=mid+1;
    }

    printf("%lld %lld\n",n-1,ans);
    return 0;
}