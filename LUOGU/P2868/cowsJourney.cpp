#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005,maxe=5005;
const double eps=1e-4,INF=1e10;

int n,e,p[maxn];
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
double value[maxe],dist[maxn];
int num[maxn];
bool vis[maxn];
queue<int> que;

void add_edge(int x,int y,int z){
    tot++;to[tot]=y;w[tot]=z;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

#define mid ((l+r)/2.0)

bool SPFA(double x){
    for (int i=1;i<=e;i++) value[i]=x*w[i]-(double)p[to[i]];
    while (!que.empty()) que.pop();

    for (int i=1;i<=n;i++) dist[i]=0,num[i]=0,vis[i]=true,que.push(i);
    while (!que.empty()){
        int head=que.front();que.pop(); vis[head]=false;
        if (num[head]>n) return true;
        for (int i=lnk[head];i;i=nxt[i]) if (dist[to[i]] > dist[head]+value[i]){
            dist[to[i]]=dist[head]+value[i]; num[to[i]]=num[head]+1;
            if (!vis[to[i]]) vis[to[i]]=true,que.push(to[i]);
        }
    }
    return false;
}

signed main(){
    n=read();e=read();
    for (int i=1;i<=n;i++) p[i]=read();
    for (int i=1;i<=e;i++){
        int x=read(),y=read(),z=read();
        add_edge(x,y,z);
    }

    double ans=0.0,l=0.0,r=1000000.0;
    while (r-l > eps){
        if (SPFA(mid)) ans=mid,l=mid+eps; else r=mid-eps;
    }
    printf("%.2lf\n",ans);
    return 0;
}