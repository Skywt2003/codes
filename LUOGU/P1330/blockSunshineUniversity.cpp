#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=10005,maxe=100005;
const int INF=1<<30;

int n,m,ans=0;

int tot=0,lnk[maxn],nxt[maxe*2],to[maxe*2];

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

bool vis[maxn];
int color[maxn],cnt=0,clo=0;

bool suc=false;

void DFS(int x,int c){
    if (!suc) return;
    color[x]=c; clo+=c;
    vis[x]=true; cnt++;
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[to[i]]) DFS(to[i],1-c);
        else if (color[to[i]]!=1-c) {suc=false;return;}
}

signed main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        add_edge(x,y);add_edge(y,x);
    }

    for (int i=1;i<=n;i++) if (!vis[i]){
        suc=true; cnt=clo=0;
        DFS(i,0); if (!suc) {printf("Impossible\n");return 0;}
        ans+=min(clo,cnt-clo);
    }
    printf("%d\n",ans);
    return 0;
}
