#include<bits/stdc++.h>

using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=2e5+5;
const int N=2e5;

int n,q;
int a[maxn];

class indexTree{
    private:
        int a[maxn];

        int lowbit(int x) {return x&(-x);}
    
    public:
        void update(int x,int delta){
            while (x<=N) a[x]+=delta,x+=lowbit(x);
        }

        int query(int x){
            int ret=0;
            while (x) ret+=a[x],x-=lowbit(x);
            return ret;
        }
};

int cnt[maxn];
indexTree t;
int sum[maxn];

int get_answer(int x){
    int ans=n*x;
    int sq=sqrt(N);

    for (int i=1;i<=sq;i++) ans+=cnt[i]*(1-i)*(x/i);
    sum[sq]=t.query(sq);
    for (int l=sq+1,r;l<=x;l=r+1){
        r=x/(x/l);
        sum[r]=t.query(r);
        ans+=(x/l)*(sum[r]-sum[l-1]);
    }
    return ans;
}

signed main(){
    n=read(); q=read();
    for (int i=1;i<=n;i++) a[i]=read(),t.update(a[i],1-a[i]),cnt[a[i]]++;

    while (q--){
        int opt=read();
        if (opt==1){
            int x=read(),y=read();
            cnt[a[x]]--; cnt[y]++;
            t.update(a[x],-(1-a[x])); t.update(y,1-y);
            a[x]=y;
        } else {
            int x=read();
            printf("%lld\n",get_answer(x));
        }
    }

    return 0;
}