#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005;
int n,m;

struct road{
    int x,y,z;
};
road a[maxn];

int cnt;
int fa[maxn];

void init(int n){
    for (int i=1;i<=n;i++) fa[i]=i;
}

int getfa(int x){
    if (fa[x]==x) return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}

void merge(int x,int y){
    x=getfa(x);y=getfa(y);
    if (x==y) return;
    fa[x]=y; cnt--;
}


bool compare_time(road aa,road bb){
    return aa.z<bb.z;
}

signed main(){
    n=read();m=read();
    cnt=n; init(n);
    for (int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i].z=read();
    sort(a+1,a+1+m,compare_time);

    for (int i=1;i<=m;i++){
        merge(a[i].x,a[i].y);
        if (cnt==1) {printf("%lld\n",a[i].z);return 0;}
    }
    printf("-1\n");
    return 0;
}