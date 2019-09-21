#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=5005,maxe=10005;

int n,q;
int a[maxn];
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int f[maxn][20],deep[maxn];

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void build_tree(int x){
    for (int j=1;j<20;j++)
        f[x][j]=f[f[x][j-1]][j-1];
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=f[x][0]){
        f[to[i]][0]=x;
        deep[to[i]]=deep[x]+1;
        build_tree(to[i]);
    }
}

int get_lca(int x,int y){
    int ret=0;
    if (deep[x] < deep[y]) swap(x,y);
    for (int i=19;i>=0;i--) if (deep[f[x][i]]>=deep[y]) x=f[x][i];
    if (x==y) return x;
    for (int i=19;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        add_edge(x,y);add_edge(y,x);
    }

    q=read();
    deep[1]=1; build_tree(1);

    while (q--){
        int x=read(),y=read();
        int l=get_lca(x,y);
        int kua=deep[y]-deep[l]+deep[x]-deep[l],cnt=0;
        int ans=0;
        while (x!=l){
            ans+=a[x]|cnt;
            cnt++; x=f[x][0];
        }
        ans+=a[x]|cnt;
        cnt=kua;
        while (y!=l){
            ans+=a[y]|cnt;
            cnt--; y=f[y][0];
        }
        printf("%lld\n",ans);
    }
    return 0;
}