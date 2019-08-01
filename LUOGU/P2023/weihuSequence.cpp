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

int n,tt,q;

#define add_mode(x,y) (x=((x)+(y))%tt)
#define mul_mode(x,y) (x=(x)%tt*(y)%tt)

#define ls (p<<1)
#define rs ((p<<1)|1)
#define mid (((tr-tl)>>1)+tl)

class segmentTree{
    private:
        int tree[maxn*4];
        int tag_add[maxn*4],tag_mul[maxn*4];

        void push_down(int tl,int tr,int p){
            tree[ls]=(tree[ls]*tag_mul[p]%tt+tag_add[p]*(mid-tl+1)%tt)%tt;
            tree[rs]=(tree[rs]*tag_mul[p]%tt+tag_add[p]*(tr-mid  )%tt)%tt;
            tag_add[ls]=(tag_add[ls]*tag_mul[p]%tt+tag_add[p])%tt;
            tag_add[rs]=(tag_add[rs]*tag_mul[p]%tt+tag_add[p])%tt;
            mul_mode(tag_mul[ls],tag_mul[p]),mul_mode(tag_mul[rs],tag_mul[p]);
            tag_add[p]=0;tag_mul[p]=1;
        }

    public:
        segmentTree(){
            memset(tree,0,sizeof(tree));
            memset(tag_add,0,sizeof(tag_add));
            fill(tag_mul,tag_mul+4*maxn,1);
        }

        void update_add(int sl,int sr,int tl,int tr,int p,int delta){
            if (sl<=tl && tr<=sr){
                add_mode(tree[p],delta*(tr-tl+1)%tt);
                add_mode(tag_add[p],delta);
                return;
            }
            push_down(tl,tr,p);
            if (sl<=mid  ) update_add(sl,sr,tl,mid,ls,delta);
            if (mid+1<=sr) update_add(sl,sr,mid+1,tr,rs,delta);
            tree[p]=(tree[ls]+tree[rs])%tt;
        }

        void update_mul(int sl,int sr,int tl,int tr,int p,int delta){
            if (sl<=tl && tr<=sr){
                mul_mode(tree[p],delta);
                mul_mode(tag_mul[p],delta);
                mul_mode(tag_add[p],delta);
                return;
            }
            push_down(tl,tr,p);
            if (sl<=mid  ) update_mul(sl,sr,tl,mid,ls,delta);
            if (mid+1<=sr) update_mul(sl,sr,mid+1,tr,rs,delta);
            tree[p]=(tree[ls]+tree[rs])%tt;
        }

        int query(int sl,int sr,int tl,int tr,int p){
            if (sl<=tl && tr<=sr) return tree[p]%tt;
            push_down(tl,tr,p);
            int ret=0;
            if (sl<=mid  ) add_mode(ret,query(sl,sr,tl,mid,ls));
            if (mid+1<=sr) add_mode(ret,query(sl,sr,mid+1,tr,rs));
            return ret;
        }
};

segmentTree t;
int a[maxn];

signed main(){
    n=read();tt=read();
    for (int i=1;i<=n;i++) a[i]=read(),t.update_add(i,i,1,n,1,a[i]%tt);
    q=read();
    for (int i=1;i<=q;i++){
        int opt=read();
        if (opt==1){
            int x=read(),y=read(),z=read();
            t.update_mul(x,y,1,n,1,z%tt);
        } else if (opt==2){
            int x=read(),y=read(),z=read();
            t.update_add(x,y,1,n,1,z%tt);
        } else if (opt==3){
            int x=read(),y=read();
            printf("%lld\n",t.query(x,y,1,n,1));
        }
    }
    return 0;
}