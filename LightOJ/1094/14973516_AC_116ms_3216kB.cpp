#define maxe maxm
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=30005,maxm=60005;
int T,n,lnk[maxn],nxt[maxe],son[maxe],w[maxe],dst[maxn],tot=0;
bool vis[maxn];
inline void add(int x,int y,int z){
    tot++;w[tot]=z;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void Init(){
    tot=0;
    memset(lnk,-1,sizeof(lnk));
    memset(nxt,-1,sizeof(nxt));
    memset(son,-1,sizeof(son));
    memset(dst,0,sizeof(dst));
    memset(vis,0,sizeof(vis));
    memset(w,0,sizeof(w));
}
inline int DFS_Far(int x,int &y){
    vis[x]=1;
    int ret=0;y=x;
    for (int i=lnk[x];i!=-1;i=nxt[i]) if (!vis[son[i]]){
        int nowy;
        int now=DFS_Far(son[i],nowy);
        if (now+w[i]>ret) ret=now+w[i],y=nowy;
    }
    return ret;
}
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    T=read();int cnt=0;
    while (T--){
        printf("Case %d: ",++cnt);
        Init();
        n=read();
        for (int i=1;i<n;i++){
            int x=read(),y=read(),z=read();
            add(x,y,z);add(y,x,z);
        }
        int x1,x2;
        int d1=DFS_Far(0,x1);
        memset(vis,0,sizeof(vis));
        int d2=DFS_Far(x1,x2);
        if (x2==0) printf("%d\n",d1); else printf("%d\n",max(d1,d2)); 
    }
    return 0;
}
