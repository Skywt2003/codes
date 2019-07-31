#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=50005,maxe=100005;
int n;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];

int ans=0;
int dist[maxn];

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void build_edges(){
    for (int i=1;i<=n;i++){
        int sum=0;
        for (int j=1;j<=(int)sqrt(i)+1;j++) if (i!=j && i%j==0){
            if (j==1) sum++; else
            if (j==i/j) sum+=j; else
            sum+=j+i/j;
        }
        if (sum<i && sum!=0) add_edge(sum,i),add_edge(i,sum);
    }
}

queue<int> que;
bool vis[maxn];

namespace Dijkstra{
    struct node{
        int x,w;

        bool operator >(node b)const{return w>b.w;}
        bool operator <(node b)const{return w<b.w;}
    };
    priority_queue <node> heap;
    bool vis[maxn];

    pair<int,int> Dijkstra(int s){
        int ret=0;
        memset(dist,0,sizeof(dist));
        memset(vis,0,sizeof(vis));
        while (!heap.empty()) heap.pop();

        vis[s]=true;
        for (int i=lnk[s];i;i=nxt[i]) if (to[i]!=s) dist[to[i]]=1,heap.push((node){to[i],dist[to[i]]});
        for (int i=1;(i<n) && (!heap.empty());i++){
            node now=heap.top();heap.pop();
            while ((!heap.empty()) && (vis[now.x] || dist[now.x]>now.w)) now=heap.top(),heap.pop();
            if (heap.empty() && (vis[now.x] || dist[now.x]<now.w)) break;
            vis[now.x]=true;
            for (int j=lnk[now.x];j;j=nxt[j]) if (vis[to[j]]==false && dist[now.x]+1>dist[to[j]]) dist[to[j]]=dist[now.x]+1,heap.push((node){to[j],dist[to[j]]});
        }
        int k=-1;
        for (int i=1;i<=n;i++) if (dist[i]>ret) ret=dist[i],k=i;
        return make_pair(ret,k);
    }
}

signed main(){
    n=read();
    
    build_edges();

    printf("%lld\n",Dijkstra::Dijkstra(Dijkstra::Dijkstra(1).second).first);
    return 0;
}