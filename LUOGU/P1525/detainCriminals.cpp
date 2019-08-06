#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=20005,maxe=100005;

int n,e;

struct edge{
    int x,y,w;
};
edge a[maxe];
int anm[maxn];

class UFA{
    private:
        int cnt,fa[maxn];
    
    public:
        UFA(int n){
            cnt=n;
            for (int i=1;i<=n;i++) fa[i]=i;
        }

        int getfa(int x){
            if (fa[x]==x) return x;
            fa[x]=getfa(fa[x]);
            return fa[x];
        }

        int count(){
            return cnt;
        }

        void merge(int x,int y){
            x=getfa(x);y=getfa(y);
            if (x==y) return;
            fa[x]=y; cnt--;
        }

        bool check(int x,int y){
            return getfa(x)==getfa(y);
        }
};

bool compare_w(edge aa,edge bb){
    return aa.w > bb.w;
}

int ans=0;

signed main(){
    n=read(); e=read();
    for (int i=1;i<=e;i++) a[i].x=read(),a[i].y=read(),a[i].w=read();

    UFA t(n);

    sort(a+1,a+1+e,compare_w);
    for (int i=1;i<=e;i++){
        if (t.check(a[i].x,a[i].y)){
            printf("%lld\n",a[i].w);
            return 0;
        }
        if (!anm[a[i].x]) anm[a[i].x]=a[i].y; else t.merge(anm[a[i].x],a[i].y);
        if (!anm[a[i].y]) anm[a[i].y]=a[i].x; else t.merge(anm[a[i].y],a[i].x);
    }
    printf("%lld\n",0);
    return 0;
}