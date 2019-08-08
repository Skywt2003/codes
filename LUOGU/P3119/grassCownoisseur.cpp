#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005,maxe=200005;

int n,e;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int cnt=0,dfn[maxn],low[maxn];
bool vis[maxn];
stack<int> stk;
queue<int> que;

int blt[maxn],size[maxn];
vector<int> inc[maxn];
int dist[2][maxn];

pair<int,int> edges[maxn];

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void tarjan(int x){
    dfn[x]=low[x]=++cnt;
    stk.push(x); vis[x]=true;
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
        size[x]=inc[x].size();
    }
}

void LPFA(int s,int k){ // it should be "Longest Path Faster Algorithm" here...
    while (!que.empty()) que.pop();
    memset(vis,0,sizeof(vis));
    memset(dist[k],0,sizeof(dist[k]));

    dist[k][blt[s]]=size[blt[s]]; vis[blt[s]]=true; que.push(blt[s]);
    while (!que.empty()){
        int head=que.front(); que.pop(); vis[head]=false;
        for (int j=0;j<size[head];j++)
            for (int i=lnk[inc[head][j]];i;i=nxt[i]) if (head!=blt[to[i]] && dist[k][head] + size[blt[to[i]]] > dist[k][blt[to[i]]]){
                dist[k][blt[to[i]]]=dist[k][head]+size[blt[to[i]]];
                if (!vis[blt[to[i]]]) que.push(blt[to[i]]),vis[blt[to[i]]]=true;
            }
    }
}

void reverse_edges(){
    tot=0;
    memset(lnk,0,sizeof(lnk));
    memset(nxt,0,sizeof(nxt));

    for (int i=1;i<=e;i++) add_edge(edges[i].second,edges[i].first);
}

signed main(){
    n=read();e=read();
    for (int i=1;i<=e;i++){
        edges[i].first=read(),edges[i].second=read();
        add_edge(edges[i].first,edges[i].second);
    }

    for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);

    LPFA(1,0);
    reverse_edges();
    LPFA(1,1);

    int ans=size[blt[1]];
    for (int i=1;i<=e;i++) if (blt[edges[i].second] != blt[edges[i].first] && dist[0][blt[edges[i].second]] && dist[1][blt[edges[i].first]])
        ans=max(ans,dist[0][blt[edges[i].second]]+dist[1][blt[edges[i].first ]]-size[blt[1]]);
    printf("%lld\n",ans);

    return 0;
}