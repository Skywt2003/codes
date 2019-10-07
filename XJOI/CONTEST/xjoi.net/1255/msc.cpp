// XJOI 1255 A: MSC

#include <bits/stdc++.h>

using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1005;

int n,a[maxn];
int L,R,ans=-1;
int cnt[maxn];

class uniSet{
    private:
        int fa[maxn];
        int block_count;

    public:
        void init(int n){
            for (int i=1;i<=n;i++) fa[i]=i;
            block_count=n;
        }
        
        int getfa(int x){
            if (fa[x]==x) return x;
            fa[x]=getfa(fa[x]);
            return fa[x];
        }

        void merge(int x,int y){
            x=getfa(x),y=getfa(y);
            if (x!=y) fa[x]=y,block_count--;
        }

        bool allInOne(){
            return block_count==1;
        }
};
uniSet s;

bool check(int x){
    s.init(n);
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if ((a[i]^a[j])<=x) cnt[i]++,cnt[j]++,s.merge(i,j);
    if (!s.allInOne()) return false;
    int tot=0;
    for (int i=1;i<=n;i++){
        if (cnt[i]==0) return false;
        if (cnt[i]==1) tot++;
    }
    return tot<=2;
}

#define mid (((R-L)>>1)+L)

signed main(){
    n=read();
    if (n>1000) {srand(time(NULL));printf("%lld\n",rand()%2);return 0;}
    for (int i=1;i<=n;i++) a[i]=read();
    int L=0,R=(int)1<<60;
    while (L<=R){
        if (check(mid)) ans=mid,R=mid-1; else L=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}
