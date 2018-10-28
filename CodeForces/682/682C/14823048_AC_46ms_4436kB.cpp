#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005,maxe=200005;
int n,ans=0,tot=0,a[maxn],lnk[maxn],nxt[maxe],son[maxe],w[maxe];
bool vis[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void add(int x,int y,int z){
    tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void DFS(int x,int num){
    if (num>a[x]) return;
    ans++;vis[x]=1;
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]) DFS(son[i],max(num,0)+w[i]);
    return;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=2;i<=n;i++){
        int x=read(),y=read();
        add(i,x,y);
        add(x,i,y);
    }
    DFS(1,0);
    printf("%d\n",n-ans);
    return 0;
}
