#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=105,maxe=10005;

int n,e;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];

int cnt=0,dfn[maxn],low[maxn];
bool vis[maxn];
stack<int> stk;

int blt[maxn];
vector<int> inc[maxn];

vector<int> send[maxn];
int ind[maxn],outd[maxn];

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void tarjan(int x){
    dfn[x]=low[x]=++cnt;
    stk.push(x),vis[x]=true;
    for (int i=lnk[x];i;i=nxt[i]) if (!dfn[to[i]]){
        tarjan(to[i]);
        low[x]=min(low[x],low[to[i]]);
    } else if (vis[to[i]]) low[x]=min(low[x],low[to[i]]);

    if (low[x]==dfn[x]){
        for (;;){
            int now=stk.top(); stk.pop(); vis[now]=false;
            blt[now]=x; inc[x].push_back(now);
            if (now==x) break;
        }
    }
}


signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        int x=read();
        while (x) add_edge(i,x),send[i].push_back(x),x=read();
    }

    for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);

    for (int i=1;i<=n;i++)
        for (int j=0;j<(int)send[i].size();j++)
            if (blt[send[i][j]]!=blt[i]) outd[blt[i]]++,ind[blt[send[i][j]]]++;
    int ans1=0,ans2=0,blocks=0;
    for (int i=1;i<=n;i++) if (low[i]==dfn[i]) blocks++,ans1+=ind[i]==0,ans2+=outd[i]==0;
    if (blocks==1) printf("1\n0\n"); else printf("%lld\n%lld\n",ans1,max(ans1,ans2));
    return 0;
}