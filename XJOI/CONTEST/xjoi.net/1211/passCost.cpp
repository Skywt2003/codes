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

int n,m,q;
int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2],w[maxn*2];
int f[maxn][22],val[maxn][22],deep[maxn];

void add_edge(int x,int y,int z){
    tot++;to[tot]=y;w[tot]=z;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

struct edge{
    int x,y,w;
}e[maxe];

bool compare_w(edge aa,edge bb){
    return aa.w<bb.w;
}

int fa[maxn];
int init(int n){
    for (int i=1;i<=n;i++) fa[i]=i;
}
int getfa(int x){
    if (fa[x]==x) return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}

void Kruscal(){
    sort(e+1,e+1+m,compare_w);
    init(n);
    for (int i=1;i<=m;i++){
        int fx=getfa(e[i].x),fy=getfa(e[i].y);
        if (fx==fy) continue;
        add_edge(e[i].x,e[i].y,e[i].w);add_edge(e[i].y,e[i].x,e[i].w);
        fa[fx]=fy;
    }
}

void build_tree(int x){
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=f[x][0])
        deep[to[i]]=deep[x]+1,f[to[i]][0]=x,val[to[i]][0]=w[i],build_tree(to[i]);
}

void build_lca(){
    for (int j=1;j<=21;j++)
    for (int i=1;i<=n;i++)
        f[i][j]=f[f[i][j-1]][j-1],
        val[i][j]=max(val[i][j-1],val[f[i][j-1]][j-1]);
}

int get_lca(int x,int y){
    int ret=0;
    if (deep[x]<deep[y]) swap(x,y);
    for (int i=21;i>=0;i--) if (deep[f[x][i]]>=deep[y]) ret=max(ret,val[x][i]),x=f[x][i];
    if (x==y) return ret;
    for (int i=21;i>=0;i--) if (f[x][i]!=f[y][i]) ret=max(ret,max(val[x][i],val[y][i])),x=f[x][i],y=f[y][i];
    return max(ret,max(val[x][0],val[y][0]));
}

signed main(){
    n=read();m=read();
    for (int i=1;i<=m;i++) e[i].x=read(),e[i].y=read(),e[i].w=read();

    Kruscal();
    deep[1]=1;
    build_tree(1);
    build_lca();

    q=read();
    while (q--){
        int x=read(),y=read();
        printf("%lld\n",get_lca(x,y));
    }
    return 0;
}