#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int tt=1e9+7;

const int maxn=1000005;
bool a[maxn];
bool lst;
int prem[maxn];

#define ls (p<<1)
#define rs (p<<1|1)
#define mid (((tr-tl)>>1)+tl)

class segmentTree{
    private:
        int sum[maxn*4],num[maxn*4];
        bool tag[maxn*4];

        void push_down(int tl,int tr,int p){
            if (tag[p]){
                tag[ls]=1-tag[ls]; tag[rs]=1-tag[rs];
                num[ls]=(mid-tl+1)-num[ls];
                num[rs]=(tr-mid)-num[rs];
                sum[ls]=((prem[mid+1]-prem[tl]+tt)%tt-sum[ls]+tt)%tt;
                sum[rs]=((prem[tr+1]-prem[mid+1]+tt)%tt-sum[rs]+tt)%tt;
                tag[p]=0;
            }
        }

    public:
        void build(int tl,int tr,int p){
            if (tl==tr){
                if (a[tl]) sum[p]=prem[tl];
                num[p]=a[tl];
                return;
            }
            build(tl,mid,ls);
            build(mid+1,tr,rs);
            sum[p]=(sum[ls]+sum[rs])%tt;
            num[p]=num[ls]+num[rs];
        }

        void update(int sl,int sr,int tl,int tr,int p){
            if (sl<=tl && tr<=sr){
                tag[p]=1-tag[p]; num[p]=(tr-tl+1)-num[p];
                sum[p]=((prem[tr+1]-prem[tl]+tt)%tt-sum[p]+tt)%tt;
                return;
            }
            push_down(tl,tr,p);
            if (sl<=mid)   update(sl,sr,tl,mid,ls);
            if (mid+1<=sr) update(sl,sr,mid+1,tr,rs);
            sum[p]=(sum[ls]+sum[rs])%tt;
            num[p]=num[ls]+num[rs];
        }

        int query(int sl,int sr,int tl,int tr,int p){
            if (sl<=tl && tr<=sr) return sum[p];
            push_down(tl,tr,p);
            int ret=0;
            if (sl<=mid)   ret=(ret+query(sl,sr,tl,mid,ls))%tt;
            if (mid+1<=sr) ret=(ret+query(sl,sr,mid+1,tr,rs))%tt;
            return ret;
        }

        int check(){
            return ((num[1]+lst)&1)==0;
        }
};

char s[maxn];
int n,m;

segmentTree t;

signed main(){
    scanf("%s",s+1); n=strlen(s+1);

    prem[1]=0; prem[2]=1;
    for (int i=3;i<=n+1;i++) prem[i]=prem[i-1]*2%tt;

    for (int i=1;i<=n/2;i++) swap(s[i],s[n-i+1]);
    for (int i=1;i<=n;i++) a[i]=s[i]=='1';

    lst=a[1];a[1]=0;
    t.build(1,n,1);
    printf("%lld\n",(t.query(2,n,1,n,1)+(int)lst+t.check()-(t.check()&&lst)+tt)%tt);

    m=read();
    while (m--){
        int x=read(),y=read();
        if (x>y) swap(x,y); if (x<1) x=1; if (y>=n) y=n-1,lst=1-lst;
        t.update(n-y+1,n-x+1,1,n,1);
        printf("%lld\n",(t.query(2,n,1,n,1)+(int)lst+t.check()-(t.check()&&lst)+tt)%tt);
    }
    return 0;
}