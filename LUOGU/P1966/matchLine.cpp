#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int tt=99999997;

const int maxn=100005;

int n;
pair<int,int> a[maxn],b[maxn];
int mp[maxn];

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
            while (x) tree[x]=(tree[x]+delta)%tt,x-=lowbit(x);
        }

        int query(int x){
            int ret=0;
            while (x<=n) ret=(ret+tree[x])%tt,x+=lowbit(x);
            return ret;
        }
};

indexTree t;

bool compare_first(pair<int,int> aa,pair<int,int> bb){
    return aa.first < bb.first;
}

int ans=0;

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=make_pair(read(),i);
    for (int i=1;i<=n;i++) b[i]=make_pair(read(),i);
    sort(a+1,a+1+n,compare_first);
    sort(b+1,b+1+n,compare_first);

    for (int i=1;i<=n;i++) mp[b[i].second]=a[i].second;
    for (int i=1;i<=n;i++) ans=(ans+t.query(mp[i]))%tt,t.update(mp[i],1);
    printf("%lld\n",ans);
    return 0;
}