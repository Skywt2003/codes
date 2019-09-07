#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int tt=1e9+7;

const int maxn=1000005;
bool a[maxn];

int make(int x){
    x-=2;
    if (x<0) return 1;
    return 1<<x;
}

#define ls (p<<1)
#define rs (p<<1|1)
#define mid (((tr-tl)>>1)+tl)

class segmentTree{
    private:
        int sum[maxn*4];
        bool tag[maxn*4];
        bool num[maxn*4];

        void push_down(int tl,int tr,int p){
            if (tag[p]){
                tag[ls]^=1; tag[rs]^=1;
                num[ls]^=1; num[rs]^=1;
                sum[ls]=(make(mid+1))-(make(tl))-sum[ls];
                sum[rs]=(make(tr+1))-(make(mid+1))-sum[rs];
                tag[p]=0;
            }
        }

    public:
        void build(int tl,int tr,int p){
            if (tl==tr){
                if (a[tl]) sum[p]=make(tl);
                return;
            }
            build(tl,mid,ls);
            build(mid+1,tr,rs);
            sum[p]=sum[ls]+sum[rs];
        }

        void update(int sl,int sr,int tl,int tr,int p){
            if (sl<=tl && tr<=sr){
                tag[p]^=1; num[p]^=1;
                sum[p]=(make(tr+1))-(make(tl))-sum[p];
                return;
            }
            push_down(tl,tr,p);
            if (sl<=mid)   update(sl,sr,tl,mid,ls);
            if (mid+1<=sr) update(sl,sr,mid+1,tr,rs);
            sum[p]=sum[ls]+sum[rs];
        }

        int query(int sl,int sr,int tl,int tr,int p){
            if (sl<=tl && tr<=sr) return sum[p];
            push_down(tl,tr,p);
            int ret=0;
            if (sl<=mid)   ret+=query(sl,sr,tl,mid,ls);
            if (mid+1<=sr) ret+=query(sl,sr,mid+1,tr,rs);
            return ret;
        }
};

char s[maxn];
int n,m;

segmentTree t;

signed main(){
    scanf("%s",s+1); n=strlen(s+1);
    for (int i=1;i<n/2;i++) swap(s[i],s[n-i+1]);
    for (int i=1;i<=n;i++) a[i]=s[i]=='1';

    t.build(1,n,1);
    printf("%d\n",t.query(1,n,1,n,1));

    m=read();
    while (m--){
        int x=read(),y=read();
        if (x>y) swap(x,y); if (x<1) x=1; if (y>n) y=n;
        t.update(n-y+1,n-x+1,1,n,1);
        printf("%d\n",t.query(1,n,1,n,1));
    }
    return 0;
}