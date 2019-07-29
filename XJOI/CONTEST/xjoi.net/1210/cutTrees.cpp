#include<bits/stdc++.h>
// #define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1000005;
const int INF=1e9;
int n,k[3],a[maxn];
int m,q;
int h[maxn];

struct cut{
    int x,t,b;
    bool operator <(cut bb)const{return b>bb.b;}
    bool operator >(cut bb)const{return b<bb.b;}
};
cut make_cut(int x,int t,int b){
    cut ret; ret.x=x; ret.t=t; ret.b=b;
    return ret;
}

vector<cut> opt[3];

#define ls ((p<<1))
#define rs ((p<<1)|1)
#define mid (((tr-tl)>>1)+tl)

class segmentTree{
    private:
        int tree[maxn*4];
    
    public:
        void build(int tl,int tr,int p){
            if (tl==tr) {tree[p]=h[tl];return;}
            build(tl,mid,ls); build(mid+1,tr,rs);
            tree[p]=min(tree[ls],tree[rs]);
        }

        int query(int sl,int sr,int tl,int tr,int p){
            if (sl<=tl && tr<=sr) return tree[p];
            int ret=INF;
            if (sl<=mid  ) ret=min(ret,query(sl,sr,tl,mid,ls));
            if (mid+1<=sr) ret=min(ret,query(sl,sr,mid+1,tr,rs));
            return ret;
        }
};
segmentTree t;

priority_queue<cut> heap[3];

bool compare_x(cut aa,cut bb){
    return aa.x<bb.x;
}

void build_answer(){
    for (int i=0;i<3;i++){
        sort(opt[i].begin(),opt[i].end(),compare_x);
        while (!heap[i].empty()) heap[i].pop();
    }
    int to[3]; to[0]=to[1]=to[2]=-1;
    for (int i=1;i<=n;i++){
        h[i]=a[i];
        for (int j=0;j<3;j++){
            while ((to[j]+1<opt[j].size()) && (opt[j][to[j]+1].x==i)) heap[j].push(opt[j][to[j]+1]),to[j]++;
            while ((!heap[j].empty()) && (heap[j].top().t<i)) heap[j].pop();
            if (!heap[j].empty()) h[i]=min(h[i],k[j]*i+heap[j].top().b);
        }
    }
}

signed main(){
    k[0]=read(),k[1]=read(),k[2]=read();
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    m=read();
    for (int i=1;i<=m;i++){
        int L=read(),R=read(),p=read(),b=read();
        opt[p-1].push_back(make_cut(L,R,b));
    }

    build_answer();

    t.build(1,n,1);
    q=read();
    for (int i=1;i<=q;i++){
        int L=read(),R=read();
        printf("%lld\n",t.query(L,R,1,n,1));
    }
    return 0;
}
