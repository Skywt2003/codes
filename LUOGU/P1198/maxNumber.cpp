#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=200005;

#define ls (p<<1)
#define rs ((p<<1)+1)
#define mid (((tr-tl)>>1)+tl)

class segmentTree{

    private:
        int tree[maxn*4];

    public:
        segmentTree(){memset(tree,0,sizeof(tree));}

        void update(int x,int tl,int tr,int p,int delta){
            if (x<tl || x>tr) return; else
            if (x==tl && tl==tr){
                tree[p]=delta;
                return;
            }
            if (x  <=mid) update(x,tl,mid  ,ls,delta);
            if (mid+1<=x) update(x,mid+1,tr,rs,delta);
            tree[p]=max(tree[ls],tree[rs]);
        }

        int query(int sl,int sr,int tl,int tr,int p){
            if (sl<=tl && tr<=sr) return tree[p];
            int ret=0;
            if (sl  <=mid) ret=max(ret,query(sl,sr,tl,mid  ,ls));
            if (mid+1<=sr) ret=max(ret,query(sl,sr,mid+1,tr,rs));
            return ret;
        }
};

segmentTree t;
int q,n=0,tt;

char read_char(){
    char ch=getchar();
    while (ch!='A'&&ch!='Q') ch=getchar();
    return ch;
}

signed main(){
    q=read();tt=read(); int last_ans=0;
    for (int i=1;i<=q;i++){
        char opt=read_char();
        if (opt=='Q'){
            int x=read();
            last_ans=t.query(n-x+1,n,1,q,1);
            printf("%lld\n",last_ans);
        } else {
            int x=(read()+last_ans)%tt; n++;
            t.update(n,1,q,1,x);
        }
    }
    return 0;
}