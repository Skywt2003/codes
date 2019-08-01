#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=500005;

int n,m;

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

signed main(){
    n=read();m=read();
    for (int i=1;i<=n;i++){
        int x=read();
        t.update(i,x);
    }
    while (m--){
        int opt=read();
        if (opt==1){
            int x=read(),delta=read();
            t.update(x,delta);
        } else {
            int x=read(),y=read();
            printf("%lld\n",t.query(y)-t.query(x-1));
        }
    }
    return 0;
}