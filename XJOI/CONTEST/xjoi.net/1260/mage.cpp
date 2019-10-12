#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005,maxe=1000005;
const int tt=998244353;

int n,m,a[maxn];

bool con[maxn][maxn];

int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];

int allsum=0,ans=0;

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

namespace subtask2{
    signed main(){
        int ans=0;
        for (int i=1;i<=n;i++) ans=(ans+a[i]*(allsum-a[i]+tt)%tt)%tt;
        printf("%lld\n",ans);
        return 0;
    }
};

bool vis[maxn];

void DFS(int x,int sum){
    if (x==n){
        for (int i=1;i<=n;i++) if (!vis[i]){
            bool now=false;
            for (int j=lnk[i];j;j=nxt[j]) if (vis[to[j]]) {now=true;break;}
            if (!now) return;
        }
        ans=(ans+sum*(allsum-sum+tt)%tt)%tt;
        return;
    }
    bool flg=false;
    for (int i=lnk[x+1];i;i=nxt[i]) if (vis[to[i]]) {flg=true;break;}
    if (!flg){
        vis[x+1]=true;
        DFS(x+1,(sum+a[x+1])%tt);
        vis[x+1]=false;
    }
    DFS(x+1,sum);
}

signed main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) a[i]=read()%tt,allsum=(allsum+a[i])%tt;
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        con[x][y]=con[y][x]=true;
        add_edge(x,y);add_edge(y,x);
    }
    for (int i=1;i<=n;i++) con[i][i]=false;

    if (m==n*(n-1)/2) return subtask2::main();
    
    DFS(0,0);

    printf("%lld\n",ans);
    return 0;
}