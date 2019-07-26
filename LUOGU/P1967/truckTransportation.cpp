#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=10005,maxe=50005;
const int INF=1<<30;

int n,e,q;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int f[maxn][20],g[maxn][20];
int deep[maxn];

namespace UFA{
    int fa[maxn];

    void init(int n){
        for (int i=1;i<=n;i++) fa[i]=i;
    }

    int get_fa(int x){
        if (fa[x]==x) return x;
        fa[x]=get_fa(fa[x]);
        return fa[x];
    }
}

struct edge{
    int x,y,w;
};
vector<edge> vec;

edge make_edge(int x,int y,int z){
    edge ret;
    ret.x=x; ret.y=y; ret.w=z;
    return ret;
}

bool compare(edge aa,edge bb){
    return aa.w>bb.w;
}

void add_edge(int x,int y,int z){
    tot++;to[tot]=y;w[tot]=z;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void Kruscal(){
    UFA::init(n);
    sort(vec.begin(),vec.end(),compare);
    for (int i=0;i<(int)vec.size();i++){
        int fx=UFA::get_fa(vec[i].x),fy=UFA::get_fa(vec[i].y);
        if (fx==fy) continue;
        UFA::fa[fx]=fy;
        add_edge(vec[i].x,vec[i].y,vec[i].w);
        add_edge(vec[i].y,vec[i].x,vec[i].w);
        // printf("added edge\n");
    }
}

void build_tree(int x){ // Mayve forest!!!
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=f[x][0]){
        f[to[i]][0]=x,g[to[i]][0]=w[i];
        deep[to[i]]=deep[x]+1;
        build_tree(to[i]);
    }
}

void build_lca(){
    for (int j=1;j<=18;j++)
        for (int i=1;i<=n;i++)
            f[i][j]=f[f[i][j-1]][j-1],
            g[i][j]=min(g[i][j-1],g[f[i][j-1]][j-1]);
}

int get_lca_min(int x,int y){
    if (UFA::get_fa(x) != UFA::get_fa(y)) return -1;
    int ret=INF;
    if (deep[x]<deep[y]) swap(x,y);
    for (int i=18;i>=0;i--) if (deep[f[x][i]]>=deep[y]) ret=min(ret,g[x][i]),x=f[x][i];
    if (x==y) return ret;
    for (int i=18;i>=0;i--) if (f[x][i]!=f[y][i]) ret=min(ret,min(g[x][i],g[y][i])),x=f[x][i],y=f[y][i];
    return min(ret,min(g[x][0],g[y][0]));
}

signed main(){
    n=read();e=read();
    for (int i=1;i<=e;i++){
        int x=read(),y=read(),z=read();
        vec.push_back(make_edge(x,y,z));
    }

    Kruscal();

    // memset(g,63,sizeof(g));
    for (int i=1;i<=n;i++) if (deep[i]==0) deep[i]=1,build_tree(i);//,f[i][0]=1,g[i][0]=INF;
    build_lca();

    q=read();
    while (q--){
        int x=read(),y=read();
        printf("%d\n",get_lca_min(x,y));
    }
    return 0;
}