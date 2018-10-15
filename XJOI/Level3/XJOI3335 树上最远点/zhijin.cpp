#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,tot=0,lnk[maxn],son[maxn*2],nxt[maxn*2],w[maxn*2],ans=0;
bool vis[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void add(int x,int y,int z){
    tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline int DFS(int x){
    int now[maxn];
    vis[x]=1;now[0]=0;
    int now_fst=0,now_scd=0;
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]) now[++now[0]]=DFS(son[i])+w[i];
    
    // printf("X=%d:==========\n",x);
    // for (int i=1;i<=now[0];i++) printf("%d ",now[i]);
    // printf("==============\n");

    if (now[0]==0) return 0;
    sort(now+1,now+1+now[0]);
    if (now[0]>1){
        if (now[now[0]]+now[now[0]-1]>ans) ans=now[now[0]]+now[now[0]-1];
    } else if (now[now[0]]>ans) ans=now[now[0]];
    return now[now[0]];
}
int main(){
    n=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read(),z=read();
        add(x,y,z);add(y,x,z);
    }
    DFS(1);
    printf("%d\n",ans);
    return 0;
}