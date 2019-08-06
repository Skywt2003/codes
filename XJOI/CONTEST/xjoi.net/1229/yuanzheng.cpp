#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005,N=100000;

int n;
pair<int,int> a[maxn];

class indexTree{
    private:
        int tree[maxn];
    
        int lowbit(int x){
            return x&(-x);
        }
    public:
        void update(int x,int delta){
            while (x) tree[x]+=delta,x-=lowbit(x);
        }

        int query(int x){
            int ret=0;
            while (x<=N) ret+=tree[x],x+=lowbit(x);
            return ret;
        }
};

bool compare_first(pair<int,int> aa,pair<int,int> bb){
    return aa.first < bb.first;
}

indexTree t;

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i].first=read(),a[i].second=read();
    sort(a+1,a+1+n,compare_first);

    int ans=0;
    for (int i=1;i<=n;i++){
        ans+=t.query(a[i].second);
        t.update(a[i].second,1);
    }
    printf("%lld\n",ans);
    return 0;
}