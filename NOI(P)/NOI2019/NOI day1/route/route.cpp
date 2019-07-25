#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=4005,maxe=400005,maxt=1005;
const int T=1000;

int n,m,A,B,C,INF,ans;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],p[maxe],q[maxe];
int f[maxn][maxt];
bool vis[maxn];

int getCost(int x){return A*x*x+B*x+C;}

void addEdge(int x,int y,int z,int t){
    tot++;to[tot]=y;p[tot]=z;q[tot]=t;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void BFS(int s){
    memset(vis,0,sizeof(vis));
    queue<int> que; while (!que.empty()) que.pop();
    que.push(s);vis[s]=true;
    while (!que.empty()){
        int head=que.front(); que.pop(); vis[head]=false;
        for (int j=T;j>=0;j--){
            for (int i=lnk[head];i;i=nxt[i]) if (f[head][j]!=INF && j>=q[i]){
                f[to[i]][p[i]]=min(f[to[i]][p[i]],f[head][j]+((head==n)?0:getCost(j-q[i])));
                if (!vis[to[i]]) vis[to[i]]=true,que.push(to[i]);
            }
        }
    }
}

signed main(){
    freopen("route.in","r",stdin);
    freopen("route.out","w",stdout);
    n=read();m=read();A=read();B=read();C=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),z=read(),t=read();
        addEdge(y,x,z,t);
    }

    memset(f,63,sizeof(f)); INF=f[0][0];
    for (int i=0;i<=T;i++) f[n][i]=i;
    BFS(n);
    
    ans=INF;
    for (int i=0;i<=T;i++) ans=min(ans,f[1][i]+getCost(i));
    printf("%lld\n",ans);
    return 0;
}