#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=400005,maxe=200005;

int n,m,q;
int atk[maxn],ans[maxn];
bool vis[maxn],ins[maxn];
vector<int> lnk[maxn];

int cnt=0,fa[maxn];

int getfa(int x){
    if (fa[x]==x) return fa[x];
    fa[x]=getfa(fa[x]);
    return fa[x];
}

void merge(int x,int y){
    x=getfa(x),y=getfa(y);
    if (x==y) return;
    fa[x]=y; cnt--;
}

void insert_node(int x){
    ins[x]=true;
    for (int i=0;i<lnk[x].size();i++) if (ins[lnk[x][i]]) merge(x,lnk[x][i]);
}

signed main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        lnk[x].push_back(y); lnk[y].push_back(x);
    }
    cnt=n; for (int i=0;i<n;i++) fa[i]=i;
    
    q=read();
    for (int i=1;i<=q;i++) atk[i]=read(),vis[atk[i]]=true;
    for (int i=0;i<n;i++) if (!vis[i]) insert_node(i);

    for (int i=q;i>=1;i--) ans[i]=cnt-i,insert_node(atk[i]);
    ans[0]=cnt;
    for (int i=0;i<=q;i++) printf("%lld\n",ans[i]);
    return 0;
}