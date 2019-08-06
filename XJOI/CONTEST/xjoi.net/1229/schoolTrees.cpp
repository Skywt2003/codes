#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=100005;
int n,q;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

#define ls (p<<1)
#define rs ((p<<1)|1)
#define mid (((tr-tl)>>1)+tl)

class segmentTree{
    private:
        int tree[maxn*4],tag[maxn*4];
    
        void push_down(int tl,int tr,int p){
            if (tag[p]==0) return;
            tree[ls]=tag[p]*(mid-tl+1);
            tree[rs]=tag[p]*(tr-mid);
            tag[ls]=tag[p];tag[rs]=tag[p];
            tag[p]=0;
        }
    
    public:
        segmentTree(){
            memset(tree,0,sizeof(tree));
            memset(tag,0,sizeof(tag));
        }

        void update(int sl,int sr,int tl,int tr,int p,int delta){
            if (sl<=tl && tr<=sr){
                tree[p]=delta*(tr-tl+1);
                tag[p]=delta;
                return;
            }
            push_down(tl,tr,p);
            if (sl<=mid  ) update(sl,sr,tl,mid,ls,delta);
            if (mid+1<=sr) update(sl,sr,mid+1,tr,rs,delta);
            tree[p]=tree[ls]+tree[rs];
        }

        int query(int sl,int sr,int tl,int tr,int p){
            if (sl<=tl && tr<=sr) return tree[p];
            push_down(tl,tr,p);
            int ret=0;
            if (sl<=mid  ) ret+=query(sl,sr,tl,mid,ls);
            if (mid+1<=sr) ret+=query(sl,sr,mid+1,tr,rs);
            return ret;
        }
};

segmentTree t;

signed main(){
    n=read();q=read();
    while (q--){
        int x=read(),y=read();
        t.update(x,y,0,n,1,1);
    }
    printf("%lld\n",n+1-t.query(0,n,0,n,1));
    return 0;
}