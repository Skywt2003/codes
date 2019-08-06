#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=60005;
const int N=60000;
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
        int tree[maxn*4];
    
    public:
        segmentTree(){
            memset(tree,0,sizeof(tree));
        }

        void update(int x,int tl,int tr,int p){
            if (tl==tr && tl==x) {tree[p]^=x;return;}
            if (x<=mid  ) update(x,tl,mid,ls);
            if (mid+1<=x) update(x,mid+1,tr,rs);
            tree[p]=tree[ls]^tree[rs];
        }

        int query(int sl,int sr,int tl,int tr,int p){
            if (sl<=tl && tr<=sr) return tree[p];
            int ret=0;
            if (sl<=mid  ) ret^=query(sl,sr,tl,mid,ls);
            if (mid+1<=sr) ret^=query(sl,sr,mid+1,tr,rs);
            return ret;
        }
};

segmentTree t;

char read_char(){
    char ch=getchar();
    while (ch!='A' && ch!='X' && ch!='R' && ch!=-1) ch=getchar();
    return ch;
}

signed main(){
    // freopen("testdata.in","r",stdin);
    segmentTree t;
    for (;;){
        char opt=read_char();
        if (opt==-1) break; else
        if (opt=='A' || opt=='R'){
            int x=read();
            t.update(x,1,N,1);
        } else {
            int x=read(),y=read();
            printf("%lld\n",t.query(x,y,1,N,1));
        }
    }
    return 0;
}