#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005,maxe=100005*2;

int n,k;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

int f[maxn][21],sum[maxn];
int ans[maxn];

void build_tree(int x){
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=f[x][0]){
        f[to[i]][0]=x;
        build_tree(to[i]);
    }
}

int get_grandfa(int x,int k){
    int ret=x;
    for (int i=20;i>=0;i--) if ((1<<i)<=k) k-=(1<<i),ret=f[ret][i];
    return ret?ret:0;
}

void build_answer(int x){
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=f[x][0]) build_answer(to[i]),ans[x]+=ans[to[i]];
    ans[x]+=sum[x];
}

signed main(){
    n=read();k=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        add_edge(x,y);add_edge(y,x);
    }

    build_tree(1);
    for (int j=1;j<=20;j++)
        for (int i=1;i<=n;i++)
            f[i][j]=f[f[i][j-1]][j-1];
    
    for (int i=1;i<=n;i++){
        int nfa=get_grandfa(i,k);
        sum[f[nfa][0]]--; sum[f[i][0]]++;
    }

    build_answer(1);
    for (int i=1;i<=n;i++) printf("%lld\n",ans[i]);
    return 0;
}