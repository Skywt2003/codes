#include<bits/stdc++.h>
// #define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=200005,maxe=1000005;

int n,e;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
vector<pair<int,int> > edges[maxn];

int cnt=0,dfn[maxn],low[maxn];
bool vis[maxn];
int stk[maxn],stk_top=0;

int blt[maxn]; // blt: Belongs to
vector<int> inc[maxn];

void add_edge(int x,int y,int z){
    tot++;to[tot]=y;w[tot]=z;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void tarjan(int x){
    low[x]=dfn[x]=++cnt;
    stk[++stk_top]=x; vis[x]=true;
    for (int i=lnk[x];i;i=nxt[i]) if (!dfn[to[i]]){
        tarjan(to[i]);
        low[x]=min(low[x],low[to[i]]);
    } else if (vis[to[i]]) low[x]=min(low[x],low[to[i]]);

    if (dfn[x]==low[x]){
        for (;;){
            int now=stk[stk_top]; stk_top--;
            blt[now]=x; vis[now]=false;
            inc[x].push_back(now);
            if (now==x) break;
        }
    }
}

int dist[maxn];
queue<int> que;

void SPFA(int s){
    while (!que.empty()) que.pop();
    memset(dist,63,sizeof(dist));
    memset(vis,0,sizeof(vis));

    que.push(s); vis[s]=true; dist[s]=0;
    while (!que.empty()){
        int head=que.front(); que.pop();
        for (int i=lnk[head];i;i=nxt[i]) if (dist[head]+w[i]<dist[to[i]]){
            dist[to[i]]=dist[head]+w[i];
            if (!vis[to[i]]) vis[to[i]]=true,que.push(to[i]);
        }
    }
}

signed main(){
    n=read();e=read();
    for (int i=1;i<=e;i++){
        int x=read(),y=read(),z=read();
        add_edge(x,y,z); edges[x].push_back(make_pair(y,z));
    }

    for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);

    tot=0; memset(lnk,0,sizeof(lnk)); memset(nxt,0,sizeof(nxt));

    for (int i=1;i<=n;i++) if (blt[i]==i){
        for (int j=0;j<(int)inc[i].size();j++){
            int now=inc[i][j];
            for (int k=0;k<(int)edges[now].size();k++)
                add_edge(i, blt[edges[now][k].first], edges[now][k].second);
        }
    }
    
    SPFA(blt[1]);
    printf("%d\n",dist[blt[n]]);
    return 0;
}