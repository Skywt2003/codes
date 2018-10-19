#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005,maxe=1005,maxv=2005;
int n,m,s,t,tot=0,que[maxv],lnk[maxn],nxt[maxe],son[maxe],w[maxe],dst[maxn],pre[maxn],ans[maxn],cnt[maxn];
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
int main(){
    s=read();t=read();n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),z=read();
        add(x,y,z);
    }
    memset(dst,63,sizeof(dst));
    memset(vis,0,sizeof(vis));
    int head=0,tail=1;
    que[tail]=s;vis[s]=true;dst[s]=0;
    while (head<=tail){
        head=(head+1)%maxv;
        vis[que[head]]=false;
        for (int i=lnk[que[head]];i;i=nxt[i]) if (dst[que[head]]+w[i]<dst[son[i]]) {
            cnt[son[i]]++;if (cnt[son[i]]>n){printf("You show me the wrong map!\n");return 0;}
            pre[son[i]]=que[head];
            dst[son[i]]=dst[que[head]]+w[i];
            if (vis[son[i]]==false){
                tail=(tail+1)%maxv;
                que[tail]=son[i];vis[son[i]]=true;
            }
        }
    }
    printf("%d\n",dst[t]);
    int now=t;while (t) ans[++ans[0]]=t,t=pre[t];
    for (int i=ans[0];i>1;i--) printf("%d ",ans[i]);
    printf("%d\n",ans[1]);
    return 0;
}