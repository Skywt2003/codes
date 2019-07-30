#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=10005,maxe=200005;

int n,m,q;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];

void add_edge(int x,int y,int z){
    tot++;to[tot]=y;w[tot]=z;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

bool vis[maxn];
queue<int> que;

bool check(int s,int x,int y){
    while (!que.empty()) que.pop();
    memset(vis,0,sizeof(vis));
    que.push(x); vis[x]=true;
    while (!que.empty()){
        int head=que.front(); que.pop();
        for (int i=lnk[head];i;i=nxt[i]) if ((!vis[to[i]])&&w[i]<=s) vis[to[i]]=true,que.push(to[i]);
    }
    return vis[y];
}

#define mid (((R-L)>>1)+L)

int query(int x,int y){
    int L=0,R=1e9,ans=-1;
    while (L<=R){
        if (check(mid,x,y)) ans=mid,R=mid-1; else L=mid+1;
    }
    return ans;
}

signed main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),z=read();
        add_edge(x,y,z);add_edge(y,x,z);
    }
    q=read();
    while (q--){
        int x=read(),y=read();
        printf("%lld\n",query(x,y));
    }
    return 0;
}