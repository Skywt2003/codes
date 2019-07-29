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
int n;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int f[maxn];
bool sat[maxn];

queue<int> que;

void add_edge(int x,int y,int z){
    tot++;to[tot]=y;w[tot]=z;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

bool check(int x){
    while (!que.empty()) que.pop();
    memset(f,0,sizeof(f));
    memset(sat,0,sizeof(sat));

    for (int i=1;i<=tot;i++) if (w[i]>=x) f[to[i]]++;
    for (int i=1;i<=n;i++) if (f[i]==0) return false;
    for (int i=1;i<=n;i++) if (f[i]==1) que.push(i);
    while (!que.empty()){
        int head=que.front(); que.pop();
        if (sat[head]) continue;
        int nowto=-1;
        for (int i=lnk[head];i;i=nxt[i]) if (w[i]>=x && (!sat[to[i]])){nowto=to[i];break;}
        if (nowto==-1) return false;
        sat[head]=sat[nowto]=true; f[nowto]--;
        for (int i=lnk[nowto];i;i=nxt[i]) if (w[i]>=x && (!sat[to[i]])){
            f[to[i]]--;
            if (f[to[i]]==0) return false;
            if (f[to[i]]==1) que.push(to[i]);
        }
    }
    return true;
}

#define mid ((L+R)/2)
int ans=-1e9-1;

signed main(){
    n=read();
    if (n&1){printf("no answer\n");return 0;}
    for (int i=1;i<=n;i++){
        int x=read(),y=read(),z=read();
        add_edge(x,y,z);add_edge(y,x,z);
    }

    int L=-1e9,R=1e9;
    while (L<=R) if (check(mid)) ans=mid,L=mid+1; else R=mid-1;

    if (ans==-1e9-1) printf("no answer\n"); else printf("%lld\n",ans);
    return 0;
}