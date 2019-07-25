#pragma GCC diagnostic error "-std=c++11"

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

#define ls ((p<<1))
#define rs ((p<<1)+1)
#define mid (((tr-tl)>>1)+tl)

struct record{
    int x,y,z;

    record operator +(record now){
        record ret; ret.x=x+now.x,ret.y=y+now.y,ret.z=z+now.z;
        return ret;
    }
};

record make_record(int x,int y,int z){
    record ret; ret.x=x,ret.y=y,ret.z=z;
    return ret;
}

class segmentTree{
    private:
        int sum1[maxn*4],sum2[maxn*4],sum3[maxn*4],sum4[maxn*4],sum5[maxn*4];
        // sum1: ∑ v[x]*x*x;
        // sum2: ∑ v[x]*x;
        // sum3: ∑ v[x];
        // sum4: ∑ i*i; (static)
        // sum5: ∑ i;   (static)
        int tag[maxn*4];

        void correct(int p,int delta,int len){
            sum1[p]+=delta*sum4[p];
            sum2[p]+=delta*sum5[p];
            sum3[p]+=delta*len;
            tag[p]+=delta;
        }

        void push_down(int tl,int tr,int p){
            correct(ls,tag[p],mid-tl+1),correct(rs,tag[p],tr-mid);
            tag[p]=0;
        }

        void push_up(int tl,int tr,int p){
            sum1[p]=sum1[ls]+sum1[rs];
            sum2[p]=sum2[ls]+sum2[rs];
            sum3[p]=sum3[ls]+sum3[rs];
        }

    public:
        void build(int tl,int tr,int p){
            if (tl==tr){
                sum4[p]=tl*tl,sum5[p]=tl;
                return;
            }
            build(tl,mid,ls),build(mid+1,tr,rs);
            sum4[p]=sum4[ls]+sum4[rs];
            sum5[p]=sum5[ls]+sum5[rs];
            tag[p]=sum1[p]=sum2[p]=sum3[p]=0;
        }

        void update(int sl,int sr,int tl,int tr,int p,int delta){
            if (sl<=tl && tr<=sr){
                correct(p,delta,tr-tl+1);
                return;
            }
            push_down(tl,tr,p);
            if (sl<=mid  ) update(sl,sr,tl,mid,ls,delta);
            if (mid+1<=sr) update(sl,sr,mid+1,tr,rs,delta);
            push_up(tl,tr,p);
        }

        record query(int sl,int sr,int tl,int tr,int p){
            if (sl<=tl && tr<=sr) return make_record(sum1[p],sum2[p],sum3[p]);
            push_down(tl,tr,p);
            record ret=make_record(0,0,0);
            if (sl<=mid  ) ret=ret+query(sl,sr,tl,mid,ls);
            if (mid+1<=sr) ret=ret+query(sl,sr,mid+1,tr,rs);
            return ret;
        }
};

inline char read_char(){
    char ch=getchar();
    while (ch!='C' && ch!='Q') ch=getchar();
    return ch;
}

inline int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

int calc(record now,int l,int r){
    return -now.x+(l+r-1)*now.y+(r-l*r)*now.z;
}

segmentTree t;
int n,q;

signed main(){
    n=read();q=read();
    t.build(1,n,1);
    while (q--){
        char opt=read_char();
        if (opt=='C'){
            int l=read(),r=read(),delta=read();
            t.update(l,r-1,1,n,1,delta);
        } else {
            int l=read(),r=read();
            int ans1=calc(t.query(l,r-1,1,n,1),l,r),ans2=(r-l)*(r-l+1)/2;
            int g=gcd(ans1,ans2);
            printf("%lld/%lld\n",ans1/g,ans2/g);
        }
    }
    return 0;
}