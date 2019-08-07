#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=10005,maxe=100005;

int n,e;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int cnt=0,dfn[maxn],low[maxn];

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

stack<int> stk;
bool vis[maxn];
int blt[maxn];
vector<int> inc[maxn];

void tarjan(int x){
    low[x]=dfn[x]=++cnt;
    stk.push(x); vis[x]=true;
    for (int i=lnk[x];i;i=nxt[i]) if (!dfn[to[i]]){
        tarjan(to[i]);
        low[x]=min(low[x],low[to[i]]);
    } else if (vis[to[i]]) low[x]=min(low[x],low[to[i]]);

    if (dfn[x]==low[x]){
        for (;;){
            int now=stk.top(); stk.pop();
            vis[now]=false;
            blt[now]=x; inc[x].push_back(now);
            if (now==x) break;
        }
    }
}

int f[maxn];

signed main(){
    n=read();e=read();
    for (int i=1;i<=e;i++){
        int x=read(),y=read();
        add_edge(x,y);
    }
    
    for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);

    for (int i=1;i<=n;i++)
        for (int j=lnk[i];j;j=nxt[j])
            if (blt[i]!=blt[to[j]]) f[blt[i]]++;

    int ans=-1;
    for (int i=1;i<=n;i++) if (blt[i]==i && f[i]==0){
        if (ans!=-1) {printf("0\n");return 0;}
        ans=inc[i].size();
    }
    printf("%lld\n",ans);
    return 0;
}