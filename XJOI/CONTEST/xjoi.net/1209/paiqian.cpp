#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005,maxe=200005;

int n,m,root;
int fa[maxn],cost[maxn],lead[maxn];
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int sum[maxn],size[maxn];
priority_queue<int> heap[maxn];
int ans=0;
int id[maxn];

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void make_answer(int x){
    id[x]=x;
    while (!heap[id[x]].empty()) heap[id[x]].pop();
    heap[id[x]].push(cost[x]); sum[id[x]]=cost[x]; size[id[x]]=1;
    for (int i=lnk[x];i;i=nxt[i]){
        make_answer(to[i]);
        if (size[to[i]] < size[x]){
            while (!heap[id[to[i]]].empty()){
                int now=heap[id[to[i]]].top();heap[id[to[i]]].pop();
                heap[id[x]].push(now);sum[x]+=now,size[x]++;
            }
        } else {
            while (!heap[id[x]].empty()){
                int now=heap[id[x]].top();heap[id[x]].pop();
                heap[id[to[i]]].push(now),sum[to[i]]+=now,size[to[i]]++;
            }
            id[x]=id[to[i]];
            sum[x]=sum[to[i]];size[x]=size[to[i]];
        }
        while (sum[x] > m){
            int now=heap[id[x]].top();heap[id[x]].pop();
            sum[x]-=now; size[x]--;
        }
    }
    ans=max(ans,lead[x]*size[x]);
}

signed main(){
    n=read();m=read();
    for (int i=1;i<=n;i++){
        fa[i]=read(),cost[i]=read(),lead[i]=read();
        if (fa[i]) add_edge(fa[i],i); else root=i;
    }

    make_answer(root);

    printf("%lld\n",ans);
    return 0;
}