#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=1005,maxe=2005;
int s,t,n,e,lnk[maxn],nxt[maxe],son[maxe],w[maxe],dst[maxn],pre[maxn],ans[maxn],tot=0,INF;
bool vis[maxn];
struct NodeInfo{
    int id,dst;
    bool operator <(const NodeInfo bb)const{
        return dst>bb.dst;
    }
};
priority_queue <NodeInfo> heap;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void add(int x,int y,int z){
    tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void Dijkstra(){
    memset(dst,0x3f,sizeof(dst));
    INF=dst[0];dst[s]=0;
    heap.push((NodeInfo){s,0});
    for (int i=1;i<=n;i++){
        int k=-1;
        while (1){
            if (heap.size()==0) break;
            NodeInfo now=heap.top();
            if (dst[now.id]!=now.dst||vis[now.id]) heap.pop(); else {k=now.id;break;}
        }
        if (k==-1) break;
        vis[k]=1;
        // printf("Get K=%d from heap.\n",k);
        for (int j=lnk[k];j;j=nxt[j]) if (!vis[son[j]]&&dst[k]+w[j]<dst[son[j]]){
            dst[son[j]]=dst[k]+w[j];
            pre[son[j]]=k;
            heap.push((NodeInfo){son[j],dst[son[j]]});
        }
    }
}
int main(){
    s=read();t=read();
    n=read();e=read();
    for (int i=1;i<=e;i++){
        int x=read(),y=read(),z=read();
        add(x,y,z);add(y,x,z);
    }
    Dijkstra();
    printf("%d\n",dst[t]);
    int x=t;
    while (x){
        ans[++ans[0]]=x;
        x=pre[x];
    }
    for (int i=ans[0];i>=1;i--) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}