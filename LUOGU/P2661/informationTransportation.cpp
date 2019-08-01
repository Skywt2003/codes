#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=200005;
const int INF=1<<30;

int n,to[maxn],f[maxn];

int fa[maxn],cnt[maxn];
int ans=INF;

int get_fa(int x){
    if (fa[x]==x) return x;
    fa[x]=get_fa(fa[x]);
    return fa[x];
}

void merge(int x,int y){
    x=get_fa(x); y=get_fa(y);
    if (x==y) return;
    fa[x]=y; cnt[y]+=cnt[x]; cnt[x]=0;
}

void init(int n){
    for (int i=1;i<=n;i++) fa[i]=i,cnt[i]=1;
}

queue<int> que;

void Topology(){
    while (!que.empty()) que.pop();
    for (int i=1;i<=n;i++) if (f[i]==0) que.push(i);
    while (!que.empty()){
        int head=que.front(); que.pop();
        f[to[head]]--;
        if (f[to[head]]==0) que.push(to[head]);
    }
}

void make_answer(){
    init(n);
    for (int i=1;i<=n;i++) if (f[i]) merge(i,to[i]);
    for (int i=1;i<=n;i++) if (f[i] && cnt[i]) ans=min(ans,cnt[i]);
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        to[i]=read();
        f[to[i]]++;
    }
    Topology();
    make_answer();

    printf("%lld\n",ans);
    return 0;
}