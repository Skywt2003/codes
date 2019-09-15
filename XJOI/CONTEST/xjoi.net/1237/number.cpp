#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1e6+5;

int t,k,m;

class indexTree{
    private:
        int a[maxn];

        int lowbit(int x){
            return x&(-x);
        }
    
    public:
        void update(int x,int delta){
            while (x) a[x]+=delta,x-=lowbit(x);
        }

        int query(int x){
            int ret=0;
            while (x<=m) ret+=a[x],x+=lowbit(x);
            return ret;
        }
};

indexTree tree;
vector<int> ans;

int fac[maxn];

void build(){
    for (int i=1;i<=m;i++)
        for (int j=i;j<=m;j+=i)
            fac[j]++;
    
    for (int i=1;i<=m;i++){
        int now=tree.query(fac[i]+1);
        if (now<=k) ans.push_back(i);
        tree.update(fac[i],1);
    }
}

signed main(){
    t=read();k=read();m=read();

    build();

    while (t--){
        int x=read();
        printf("%lld\n",ans[x-1]);
    }
    // for (int i=0;i<ans.size();i++) printf("%lld ",ans[i]); printf("\n");
    return 0;
}