#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int maxn=10005*21,maxe=100005*21*5,maxk=25;

int n,m,k;
int dist[maxn];

int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];

void add_edge(int x,int y,int z){
    tot++; to[tot]=y; w[tot]=z;
    nxt[tot]=lnk[x]; lnk[x]=tot;
}

struct node{
    int x,w;

    bool operator <(node bb)const{
        return w>bb.w;
    }
    bool operator >(node bb)const{
        return w<bb.w;
    }
};

priority_queue<node> heap;
bool vis[maxn];

void Dijkstra(){
    while (!heap.empty()) heap.pop();
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));

    dist[1]=0;
    heap.push((node){1,0});
    while (!heap.empty()){
        node head=heap.top(); heap.pop();
        if (vis[head.x]) continue;
        vis[head.x]=true;
        for (int i=lnk[head.x];i;i=nxt[i]) if (dist[head.x]+w[i] < dist[to[i]]){
            dist[to[i]]=dist[head.x]+w[i];
            if (!vis[to[i]]) heap.push((node){to[i],dist[to[i]]});
        }
    }
}

signed main(){
    n=read(); m=read(); k=read()+1;
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),z=read();
        for (int i=x,j=y;i<=n*k&&j<=n*k;i+=n,j+=n) add_edge(i,j,z),add_edge(j,i,z);
        for (int i=x,j=y+n;i<=n*k&&j<=n*k;i+=n,j+=n) add_edge(i,j,0);
        for (int i=x+n,j=y;i<=n*k&&j<=n*k;i+=n,j+=n) add_edge(j,i,0);
    }

    Dijkstra();

    int ans=INF;
    for (int i=n;i<=n*k;i+=n) ans=min(ans,dist[i]);
    printf("%lld\n",ans);
    return 0;
}