#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=500005,maxv=1000005;

int n,q,a[maxn],last[maxv];

class indexTree{
    private:
        int tree[maxn];

        int lowbit(int x){
            return x&(-x);
        }

    public:
        indexTree(){
            memset(tree,0,sizeof(tree));
        }

        void update(int x,int delta){
            while (x<=n) tree[x]+=delta,x+=lowbit(x);
        }

        int query(int x){
            int ret=0;
            while (x) ret+=tree[x],x-=lowbit(x);
            return ret;
        }
};

indexTree t;

struct qry{
    int l,r,id,ans;
};

qry b[maxn];

bool compare_r(qry aa,qry bb){
    return aa.r < bb.r;
}

bool compare_id(qry aa,qry bb){
    return aa.id < bb.id;
}

signed main(){
    memset(last,-1,sizeof(last));

    n=read();
    for (int i=1;i<=n;i++) a[i]=read();

    q=read();
    for (int i=1;i<=q;i++) b[i].l=read(),b[i].r=read(),b[i].id=i;
    sort(b+1,b+1+q,compare_r);

    int tor=0;
    for (int i=1;i<=q;i++){
        if (tor < b[i].r){
            for (int j=tor+1;j<=b[i].r;j++){
                if (last[a[j]]!=-1) t.update(last[a[j]],-1);
                last[a[j]]=j; t.update(j,1);
            }
            tor=b[i].r;
        }
        b[i].ans=t.query(b[i].r)-t.query(b[i].l-1);
    }

    sort(b+1,b+1+q,compare_id);
    for (int i=1;i<=q;i++) printf("%lld\n",b[i].ans);
    return 0;
}