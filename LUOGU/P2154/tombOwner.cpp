#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int tt=2147483648;
const int maxw=10005,maxk=15;

int n,m,w,k;
int c[maxw][maxk];

pair<int,int> a[maxw];

class indexTree{
    private:
        int tree[maxw];
        int lowbit(int x){return x&(-x);}
    
    public:
        void update(int x,int delta){
            while (x<=w) tree[x]=(tree[x]+delta%tt)%tt,x+=lowbit(x);
        }

        int query(int x){
            int ret=0;
            while (x) ret=(ret+tree[x])%tt,x-=lowbit(x);
            return ret;
        }
};

void build_cons(){
    c[0][0]=1;
    for (int i=1;i<=w;i++){
        c[i][0]=1;
        if (i<=k) c[i][i]=1;
        for (int j=1;j<min(i,k+1);j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%tt;
    }
}

bool compare_double_key(pair<int,int> aa,pair<int,int> bb){
    return (aa.first < bb.first) || ((aa.first == bb.first) && (aa.second < bb.second));
}

bool compare_second(pair<int,int> aa,pair<int,int> bb){
    return aa.second < bb.second;
}

int sum[maxw],total[maxw];
indexTree tup,tdown;
int ans=0;

void discretize(){
    sort(a+1,a+1+w,compare_second);
    int x=0,last=-1;
    for (int i=1;i<=w;i++){
        if (a[i].second !=last){
            last=a[i].second;
            a[i].second=++x;
        } else a[i].second=x;
    }

    sort(a+1,a+1+w,compare_double_key);
    x=0,last=-1;
    for (int i=1;i<=w;i++){
        if (a[i].first !=last){
            last=a[i].first;
            a[i].first=++x;
        } else a[i].first=x;
    }

    // printf("AFTER DISCRETIOZE:\n");
    // for (int i=1;i<=w;i++) printf("%lld %lld\n",a[i].first,a[i].second);
    // printf("\n");
}

signed main(){
    n=read(); m=read();
    w=read();
    for (int i=1;i<=w;i++) a[i].first=read(),a[i].second=read();
    k=read();

    build_cons();

    discretize();
    for (int i=1;i<=w;i++) total[a[i].second]++;

    for (int i=1;i<=w;i++) if (i==1 || a[i].second != a[i-1].second) tdown.update(a[i].second,c[total[a[i].second]][k]);

    for (int i=2,j;i<=w;i=j+1){
        j=i;
        while (j+1<=w && a[j+1].first==a[i].first) j++;
        for (int t=i;t<=j;t++){
            tup.update(a[t].second,tt-c[sum[a[t].second]][k]);
            tdown.update(a[t].second,tt-c[total[a[t].second]-sum[a[t].second]][k]);
            sum[a[t].second]++;
            tup.update(a[t].second,c[sum[a[t].second]][k]);
            tdown.update(a[t].second,c[total[a[t].second]-sum[a[t].second]][k]);

            int l=t-i,r=j-t+1;
            if (l<k || r<k) continue;
            if (a[t].second == a[t-1].second+1) continue;
            ans=ans + c[l][k]%tt*
                      c[r][k]%tt*
                      (tup.query(a[t].second-1)-tup.query(a[t-1].second)+tt)%tt*
                      (tdown.query(a[t].second-1)-tdown.query(a[t-1].second)+tt)%tt;
            printf("x=%lld [%lld to %lld] added answer: %lld %lld %lld %lld",
                a[t].first,
                a[t-1].second,
                a[t].second,
                c[l][k],
                c[r][k],
                tup.query(a[t].second-1)-tup.query(a[t-1].second),
                tdown.query(a[t].second-1)-tdown.query(a[t-1].second));
        }
    }
    printf("%lld\n",ans);
    return 0;
}