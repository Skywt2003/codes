#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=1<<30;
const int maxn=300005;
int n,m;

pair<int,int> b[maxn];

int a[maxn];

double get_sloop(int i,int x,int j,int y){
    return 1.0*(x-y)/(i-j);
}

double get_sloop(pair<int,int> aa,pair<int,int> bb){
    return 1.0*((double)aa.second-bb.second)/(bb.first-aa.first);
}

pair<int,int> stk[maxn]; // first is ID and second is value
int stk_top=0;
int ans[maxn];

bool compare_second(pair<int,int> aa,pair<int,int> bb){
    return aa.second < bb.second;
}

signed main(){
    memset(ans,-1,sizeof(ans));

    n=read();m=read();
    for (int i=1;i<=n;i++){
        a[i]=read();
        if (stk_top>=1 && a[i] >= stk[stk_top].second) continue;
        while (stk_top>=2 && get_sloop(stk[stk_top-1],stk[stk_top])<get_sloop(stk[stk_top],make_pair(i,a[i]))) stk_top--;
        stk[++stk_top]=make_pair(i,a[i]);
    }
    for (int i=1;i<=m;i++) b[i]=make_pair(i,read());

    // printf("In stack: \n");
    // for (int i=1;i<=stk_top;i++) printf("%lld ",stk[i].second);printf("\n");
    // for (int i=1;i<=stk_top;i++) printf("%lld ",stk[i].first);printf("\n");

    sort(b+1,b+1+m,compare_second);
    for (int i=1;i<=m;i++) if (b[i].second >= 0){
        while (stk_top>=2 && get_sloop(stk[stk_top-1],stk[stk_top]) < b[i].second) stk_top--;
        ans[b[i].first]=stk[stk_top].second + b[i].second*stk[stk_top].first;
    } else b[i].second=-b[i].second;

    // solve down order

    stk_top=0;
    for (int i=n;i>=1;i--){
        if (stk_top>=1 && a[i] >= stk[stk_top].second) continue;
        while (stk_top>=2 && -get_sloop(stk[stk_top-1],stk[stk_top])<-get_sloop(stk[stk_top],make_pair(i,a[i]))) stk_top--;
        stk[++stk_top]=make_pair(i,a[i]);
    }

    // printf("In stack: \n");
    // for (int i=1;i<=stk_top;i++) printf("%lld ",stk[i].second);printf("\n");
    // for (int i=1;i<=stk_top;i++) printf("%lld ",stk[i].first);printf("\n");

    for (int i=m;i>=1;i--) if (ans[b[i].first]==-1){
        while (stk_top>=2 && -1.0*get_sloop(stk[stk_top-1],stk[stk_top]) < b[i].second) stk_top--;
        ans[b[i].first]=stk[stk_top].second - b[i].second*stk[stk_top].first;
    }

    for (int i=1;i<=m;i++) printf("%lld ",ans[i]); printf("\n");
    return 0;
}