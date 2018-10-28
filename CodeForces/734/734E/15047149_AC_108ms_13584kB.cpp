#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=200005,maxe=400005;
int n,m=0,tot=0,lnk[maxn],nxt[maxe],son[maxe],id[maxn];
int TOT=0,LNK[maxn],SON[maxe],NXT[maxe],DST[maxn];
bool color[maxn],vis[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void add(int x,int y){
    tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void BigAdd(int X,int Y){
    TOT++;SON[TOT]=Y;NXT[TOT]=LNK[X];LNK[X]=TOT;
}
inline void DFS(int x,int now_id){
    vis[x]=1;id[x]=now_id;
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]&&color[son[i]]==color[x]) DFS(son[i],now_id);
}
inline int BigDFS(int x){
    vis[x]=1;int ret=x,ret_num=DST[x];
    for (int i=LNK[x];i;i=NXT[i]) if (!vis[SON[i]]){
        DST[SON[i]]=DST[x]+1;
        int now=BigDFS(SON[i]);
        if (DST[now]>ret_num) ret=now,ret_num=DST[now];
    }
    return ret;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) color[i]=(bool)read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    for (int i=1;i<=n;i++) if (!vis[i]) DFS(i,++m);
    for (int i=1;i<=n;i++)
        for (int j=lnk[i];j;j=nxt[j]) if (color[i]!=color[son[j]]) BigAdd(id[i],id[son[j]]);
    memset(vis,0,sizeof(vis));memset(DST,0,sizeof(DST));
    int x1=BigDFS(1);
    memset(vis,0,sizeof(vis));memset(DST,0,sizeof(DST));
    int x2=BigDFS(x1);
    printf("%d\n",DST[x2]+1>>1);
    return 0;
}
