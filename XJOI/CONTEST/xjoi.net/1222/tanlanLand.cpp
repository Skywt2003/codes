#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1e5+5;

int n,q;

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
            while (x) tree[x]+=delta,x-=lowbit(x);
        }

        int query(int x){
            int ret=0;
            while (x<=n) ret+=tree[x],x+=lowbit(x);
            return ret;
        }
};

indexTree head,tail;

signed main(){
    n=read();q=read();
    while (q--){
        int opt=read(),l=read(),r=read();
        if (opt==1) head.update(l,1),tail.update(r,1);
        else printf("%lld\n",tail.query(l)-head.query(r+1));
    }
    return 0;
}