#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1000005;
int n,m,tot=0,f[maxn][25],lnk[maxn],nxt[maxn*2],son[maxn*2],fa[maxn];
bool vis[maxn];
long long ans=0;
inline void add(int x,int y){
    tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void DFS(int x){ //构造 F 数组
    for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa[x]){
        f[son[i]][0]=x;
        for (int j=1;j<=20;j++) f[son[i]][j]=f[f[son[i]][j-1]][j-1];
        fa[son[i]]=x;DFS(son[i]);
    }
}
inline bool check(int x,int tot){
    for (int i=20;i>=0;i--){
        if (!vis[f[x][i]]) {tot-=1<<i,x=f[x][i];}
    }
    return tot>=1;
}
int main(){
    n=read();m=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    for (int i=0;i<=20;i++) f[n][i]=n;
    DFS(n);vis[n]=1;int k=n-m-1;  // k 为实际选取的数量
    for (int i=n-1;i>=1;i--){
        if (check(i,k)){
            int x=i;
            while (!vis[x]) {vis[x]=1,x=f[x][0],k--;}
        }
    }
    for (int i=1;i<=n;i++) if (!vis[i]) printf("%d ",i);
    printf("\n");
    return 0;
}