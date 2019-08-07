#include<bits/stdc++.h>
// #define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1505,maxe=2250005;
int n,e,ans=0;
int s1,t1,s2,t2;

int tot=-1,lnk[maxn],nxt[maxe],to[maxe],w[maxe];

void add_edge(int x,int y,int z){
    tot++;to[tot]=y;w[tot]=z;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

int dist[2][maxn];
queue<int> que;
bool vis[maxn];

void SPFA(int s,int k){
    while (!que.empty()) que.pop();
    memset(vis,0,sizeof(vis));
    memset(dist[k],63,sizeof(dist[k]));

    dist[k][s]=0; que.push(s); vis[s]=true;
    while (!que.empty()){
        int head=que.front(); que.pop(); vis[head]=false;
        for (int i=lnk[head];i!=-1;i=nxt[i]) if (dist[k][head]+w[i] < dist[k][to[i]]){
            dist[k][to[i]]=dist[k][head]+w[i];
            if (!vis[to[i]]) vis[to[i]]=true,que.push(to[i]);
        }
    }
}

namespace Topology{
    int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
    int f[maxn],dist[maxn];

    void clear_graph(){
        tot=0;
        memset(lnk,0,sizeof(lnk));
        memset(nxt,0,sizeof(nxt));
        memset(dist,0,sizeof(dist));
        memset(f,0,sizeof(f));
    }

    void add_edge(int x,int y,int z){
        tot++; to[tot]=y; w[tot]=z; f[y]++;
        nxt[tot]=lnk[x]; lnk[x]=tot;
    }

    void run(){
        while (!que.empty()) que.pop();
        memset(dist,0,sizeof(dist));

        for (int i=1;i<=n;i++) if (f[i]==0) que.push(i),dist[i]=0;
        while (!que.empty()){
            int head=que.front(); que.pop();
            for (int i=lnk[head];i;i=nxt[i]){
                dist[to[i]]=max(dist[to[i]],dist[head]+w[i]);
                f[to[i]]--;
                if (f[to[i]]==0) que.push(to[i]);
            }
        }

        for (int i=1;i<=n;i++) ans=max(ans,dist[i]);
    }
};

int cnt[maxe];
bool build_vis[maxn];

void rebuild1(int x,int from,int k){
    if (build_vis[x]) return; build_vis[x]=true;
    for (int i=lnk[x];i!=-1;i=nxt[i]){
        if (dist[k][to[i]]+w[i] == dist[k][x] && to[i]!=from){
            cnt[i^1]|=1<<k;
            if (cnt[i^1]==3) Topology::add_edge(to[i],x,w[i]);
            rebuild1(to[i],x,k);
        }
    }
}

void rebuild2(int x,int from,int k){
    if (build_vis[x]) return; build_vis[x]=true;
    for (int i=lnk[x];i!=-1;i=nxt[i]){
        if (dist[k][to[i]]+w[i] == dist[k][x] && to[i]!=from){
            cnt[i]|=1<<k;
            if (cnt[i]==3) Topology::add_edge(to[i],x,w[i]);
            rebuild2(to[i],x,k);
        }
    }
}

signed main(){
    memset(lnk,-1,sizeof(lnk));
    memset(nxt,-1,sizeof(nxt));

    n=read();e=read();
    s1=read(),t1=read(),s2=read(),t2=read();
    for (int i=1;i<=e;i++){
        int x=read(),y=read(),z=read();
        add_edge(x,y,z);add_edge(y,x,z);
    }

    SPFA(s1,0);
    SPFA(s2,1);

    memset(build_vis,0,sizeof(build_vis));
    rebuild1(t1,-1,0);
    memset(build_vis,0,sizeof(build_vis));
    rebuild1(t2,-1,1);
    Topology::run();

    Topology::clear_graph();
    memset(cnt,0,sizeof(cnt));
    memset(build_vis,0,sizeof(build_vis));
    rebuild1(t1,-1,0);
    memset(build_vis,0,sizeof(build_vis));
    rebuild2(t2,-1,1);
    Topology::run();

    printf("%d\n",ans);
    return 0;
}