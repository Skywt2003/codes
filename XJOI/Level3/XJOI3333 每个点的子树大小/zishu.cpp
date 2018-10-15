#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005;
int n,tot=0,fa[maxn],lnk[maxn],son[maxn],nxt[maxn],f[maxn],sum[maxn],que[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void add(int x,int y){
    tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void Topology(){
    int head=0,tail=0;
    for (int i=1;i<=n;i++) if (f[i]==0) que[++tail]=i,sum[i]=0;
    while (head!=tail){
        head++;
        for (int i=lnk[que[head]];i;i=nxt[i]) sum[que[head]]+=sum[son[i]];
        sum[que[head]]++;
        if (fa[que[head]]<1) continue;
        f[fa[que[head]]]--;
        if (f[fa[que[head]]]==0){
            que[++tail]=fa[que[head]];
        }
    }
}
int main(){
    n=read();
    for (int i=2;i<=n;i++){
        int x=read();
        fa[i]=x;
        add(x,i);
        f[x]++;
    }
    Topology();
    for (int i=1;i<=n;i++) printf("%d ",sum[i]);
    printf("\n");
    return 0;
}