#include<bits/stdc++.h>
using namespace std;

// #define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=2005,maxe=4005;

int n,m;

int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxn];
int fa[maxn],deep[maxn];
int f[maxn][25];

int dist[maxn][maxn];

void add_edge(int x,int y,int z){
    tot++;to[tot]=y;w[tot]=z;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void build_tree(int x){
    f[x][0]=fa[x];
    for (int j=1;j<=24;j++) f[x][j]=f[f[x][j-1]][j-1];

    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
        deep[to[i]]=deep[x]+1; fa[to[i]]=x;
        build_tree(to[i]);
    }
}

signed main(){
    n=read(); m=read();
    for (int i=1;i<m;i++){
        int x=read(),y=read(),z=read();
        add_edge(x,y,z);add_edge(y,x,z);
        dist[x][y]=dist[y][x]=z;
    }
}