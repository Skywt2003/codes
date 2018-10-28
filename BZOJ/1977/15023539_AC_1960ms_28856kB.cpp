#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005,maxe=300005;
int n,m,fa[maxn],f[maxn][18],to[maxn][18],deep[maxn];
int tot=0,lnk[maxn],nxt[maxe*2],son[maxe*2],w[maxe*2];
bool vis[maxn];
long long ans=(long long)1<<60,sum=0;
struct SideData{
    int x,y,w;
    bool used;
}a[maxe];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline bool cmp(SideData aa,SideData bb){
    return aa.w<bb.w;
}
inline void add(int x,int y,int z){
    tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline int getfa(int x){
    if (fa[x]==x) return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}
inline void Kruscal(){
    for (int i=1;i<=n;i++) fa[i]=i;
    int cnt=0;
    for (int i=1;i<=m&&cnt<n-1;i++){
        int fx=getfa(a[i].x),fy=getfa(a[i].y);
        if (fx==fy) continue;
        cnt++;a[i].used=1;sum+=(long long)a[i].w;
        fa[fx]=fy;
        add(a[i].x,a[i].y,a[i].w);
        add(a[i].y,a[i].x,a[i].w);
    }
}
inline void Build(int x,int id,int lst){
    vis[x]=1;
    f[x][0]=w[id];to[x][0]=lst;
    for (int i=1;i<18;i++) f[x][i]=max(f[x][i-1],f[to[x][i-1]][i-1]),to[x][i]=to[to[x][i-1]][i-1];
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]) deep[son[i]]=deep[x]+1,Build(son[i],i,x);
}
inline int Query(int x,int y){
    //printf("Query: %d %d => ",x,y);
    int ret=0;
    if (deep[x]<deep[y]) swap(x,y);
    for (int i=17;i>=0;i--) if (deep[to[x][i]]>=deep[y]) ret=max(ret,f[x][i]),x=to[x][i];
    for (int i=17;i>=0;i--) if (to[x][i]!=to[y][i]) ret=max(ret,max(f[x][i],f[y][i])),x=to[x][i],y=to[y][i];
    ret=max(ret,max(f[x][0],f[y][0]));
    //printf("%d %d\n",x,y);
    return ret;
}
inline int ExQuery(int x,int y,int z){
    int ret=0;
    if (deep[x]<deep[y]) swap(x,y);
    for (int i=17;i>=0;i--) if (deep[to[x][i]]>=deep[y]){
        if (f[x][i]!=z) ret=max(ret,f[x][i]);
        x=to[x][i];
    }
    for (int i=17;i>=0;i--) if (to[x][i]!=to[y][i]){
        if (f[x][i]!=z) ret=max(ret,f[x][i]);
        if (f[y][i]!=z) ret=max(ret,f[y][i]);
        x=to[x][i];y=to[y][i];
    }
    if (f[x][0]!=z) ret=max(ret,f[x][0]);
    if (f[y][0]!=z) ret=max(ret,f[y][0]);
    return ret;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i].w=read();
    sort(a+1,a+1+m,cmp);
    Kruscal();
    deep[1]=1;
    Build(1,0,0);
    for (int i=1;i<=m;i++) if (!a[i].used){
        int qry=Query(a[i].x,a[i].y);
        if (qry==a[i].w) qry=ExQuery(a[i].x,a[i].y,qry);
        long long now=sum-(long long)qry+(long long)a[i].w;
        if (now>sum) ans=min(ans,now);
    }
    printf("%lld\n",ans);
    return 0;
}
