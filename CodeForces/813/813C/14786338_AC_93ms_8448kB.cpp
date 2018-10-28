#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=200005,maxe=400005;
int n,s,tot=0,lnk[maxn],nxt[maxe],son[maxe],dst[2][maxn],ans=0;
bool vis[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void add(int x,int y){
    tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void DFS(int k,int x){
    vis[x]=1;
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]){
        dst[k][son[i]]=dst[k][x]+1;
        DFS(k,son[i]);
    }
}
int main(){
    n=read();s=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    DFS(0,1);
    memset(vis,0,sizeof(vis));
    DFS(1,s);
    for (int i=1;i<=n;i++) if (dst[0][i]>dst[1][i]) ans=max(ans,dst[0][i]*2);
    printf("%d\n",ans);
    return 0;
}
