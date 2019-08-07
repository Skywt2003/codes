#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=10005,maxe=20005;
const int INF=4557430888798830399;

int n,e;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];

void add_edge(int x,int y,int z){
    tot++;to[tot]=y;w[tot]=z;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

int dist[maxn];
bool vis[maxn];
queue<int> que;
bool used[maxn];

bool SPFA(int s){
    while (!que.empty()) que.pop();
    memset(vis,0,sizeof(vis));
    // memset(dist,63,sizeof(dist));
    memset(used,0,sizeof(used));

    dist[s]=0; vis[s]=used[s]=true; que.push(s);
    while (!que.empty()){
        int head=que.front(); que.pop(); vis[head]=false;
        for (int i=lnk[head];i;i=nxt[i]) if (dist[head]+w[i]<dist[to[i]]){
            dist[to[i]]=dist[head]+w[i];
            if (!vis[to[i]]){
                if (used[to[i]]) return false;
                vis[to[i]]=used[to[i]]=true,que.push(to[i]);
            }
        }
    }
    return true;
}

int f[maxn];

signed main(){
    // freopen("testdata.in","r",stdin);
    n=read();e=read();
    for (int i=1;i<=e;i++){
        int opt=read();
        if (opt==1){
            int x=read(),y=read(),z=read();
            add_edge(y,x,-z); f[y]++;
        } else if (opt==2){
            int x=read(),y=read(),z=read();
            add_edge(x,y,z); f[x]++;
        } else if (opt==3){
            int x=read(),y=read();
            add_edge(x,y,0);add_edge(y,x,0); f[x]++,f[y]++;
        }
    }

    memset(dist,63,sizeof(dist));
    for (int i=1;i<=n;i++) if (dist[i]==INF){
        if (!SPFA(i)) {printf("No\n");return 0;}
    }
    printf("Yes\n");
    return 0;
}