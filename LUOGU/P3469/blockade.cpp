#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005,maxe=1000005;

int n,e;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int cnt=0,dfn[maxn],low[maxn],size[maxn],ans[maxn];
bool cut[maxn];
vector<int> vec[maxn];

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void ex_tarjan(int x,int fa){
    low[x]=dfn[x]=++cnt; size[x]++;
    int now_sum=0;
    for (int i=lnk[x];i;i=nxt[i]) if (!dfn[to[i]]){
        ex_tarjan(to[i],x);
        low[x]=min(low[x],low[to[i]]);
        size[x]+=size[to[i]];
        if (low[to[i]]>=dfn[x]){
            cut[x]=true;
            vec[x].push_back(size[to[i]]); now_sum+=size[to[i]];
        }
    } else if (to[i]!=fa) low[x]=min(low[x],low[to[i]]);
    
    if (cut[x] && n!=now_sum+1) vec[x].push_back(n-now_sum-1);
}

signed main(){
    n=read();e=read();
    for (int i=1;i<=e;i++){
        int x=read(),y=read();
        add_edge(x,y); add_edge(y,x);
    }

    for (int i=1;i<=n;i++) if (!dfn[i]) ex_tarjan(i,-1);
        
    for (int k=1;k<=n;k++){
        int ans=2*(n-1);
        for (int i=0;i<(int)vec[k].size();i++)
            for (int j=i+1;j<(int)vec[k].size();j++){
                ans+=2*vec[k][i]*vec[k][j];
            }
        printf("%lld\n",ans);
    }
    return 0;
}