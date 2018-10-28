#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=30005,maxm=60005,maxe=50005;
int n,m,q,w[maxn],fa[maxn],deep[maxn],sum=0;
int tot=0,lnk[maxn],nxt[maxm],son[maxm];
int f[maxn][20],max_num[maxn][20],min_num[maxn][20],dif_upd[maxn][20],dif_dwn[maxn][20];
bool vis[maxn];
struct Edge{
    int x,y,w;
}e[maxe];
inline int max3(int x,int y,int z){
    return z>max(x,y)?z:max(x,y);
}
inline bool Compare(Edge a,Edge b){
    return a.w>b.w;
}
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline int Abs(int x){
    return x<0?-x:x;
}
inline void add(int x,int y){
    tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void Init(){
    memset(w,0,sizeof(w));
    memset(fa,0,sizeof(fa));
    memset(deep,0,sizeof(deep));
    memset(f,0,sizeof(f));
    memset(max_num,0,sizeof(max_num));
    memset(min_num,0,sizeof(min_num));
    memset(dif_upd,0,sizeof(dif_upd));
    memset(dif_dwn,0,sizeof(dif_dwn));
    tot=0;sum=0;
    memset(lnk,0,sizeof(lnk));
    memset(nxt,0,sizeof(nxt));
    memset(son,0,sizeof(son));
    memset(vis,0,sizeof(vis));
    memset(e,0,sizeof(e));
}
inline int getfa(int x){
    if (fa[x]==x) return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}
inline void Kruskal(){
    sort(e+1,e+1+m,Compare);
    for (int i=1;i<=n;i++) fa[i]=i;
    int cnt=0;
    for (int i=1;i<=m&&cnt<n-1;i++){
        int fx=getfa(e[i].x),fy=getfa(e[i].y);
        if (fx==fy) continue;
        sum+=e[i].w;
        add(e[i].x,e[i].y);add(e[i].y,e[i].x);
        fa[fx]=fy;cnt++;
    }
    if (cnt!=n-1) printf("ERROR!!!!!\n");
}
inline void BuildTree(int x){
    vis[x]=1;
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]){
        fa[son[i]]=x;
        deep[son[i]]=deep[x]+1;
        BuildTree(son[i]);
    }
}
inline void Build(){
    for (int i=1;i<=n;i++){
        f[i][0]=fa[i];
        max_num[i][0]=max(w[i],w[fa[i]]);
        min_num[i][0]=min(w[i],w[fa[i]]);
        dif_upd[i][0]=w[fa[i]]-w[i];dif_dwn[i][0]=w[i]-w[fa[i]];
    }
    for (int j=1;j<20;j++)
        for (int i=1;i<=n;i++){
            f[i][j]=f[f[i][j-1]][j-1];
            max_num[i][j]=max(max_num[i][j-1],max_num[f[i][j-1]][j-1]);
            min_num[i][j]=min(min_num[i][j-1],min_num[f[i][j-1]][j-1]);
            dif_upd[i][j]=max3(dif_upd[i][j-1],dif_upd[f[i][j-1]][j-1],max_num[f[i][j-1]][j-1]-min_num[i][j-1]);
            dif_dwn[i][j]=max3(dif_dwn[i][j-1],dif_dwn[f[i][j-1]][j-1],max_num[i][j-1]-min_num[f[i][j-1]][j-1]);
        }
    // for (int i=1;i<=n;i++){
    //     printf("I=%d -------------\n",i);
    //     for (int j=0;j<19;j++) printf("%d ",f[i][j]);printf("\n");
    //     printf("MAX_NUM: ");for (int j=0;j<19;j++) printf("%d ",max_num[i][j]);printf("\n");
    //     printf("MIN_NUM: ");for (int j=0;j<19;j++) printf("%d ",min_num[i][j]);printf("\n");
    //     printf("DIF_UPD: ");for (int j=0;j<19;j++) printf("%d ",dif_upd[i][j]);printf("\n");
    //     printf("DIF_DWN: ");for (int j=0;j<19;j++) printf("%d ",dif_dwn[i][j]);printf("\n");
    //     printf("\n");
    // }
}
inline int GetAnswer(int x,int y){
    int ret=0;
    int now_min=1e8,now_max=0;
    if (x==y) return 0;
    for (int i=19;i>=0;i--) if (deep[f[x][i]]>=deep[y]){
        ret=max3(ret, max_num[x][i]-now_min, dif_upd[x][i]);
        now_min=min(now_min,min_num[x][i]);
        x=f[x][i];
    }
    for (int i=19;i>=0;i--) if (deep[f[y][i]]>=deep[x]){
        ret=max3(ret, now_max-min_num[y][i], dif_dwn[y][i]);
        now_max=max(now_max,max_num[y][i]);
        y=f[y][i];
    }
    if (x==y) return ret;
    for (int i=19;i>=0;i--) if (f[x][i]!=f[y][i]){
        ret=max3(ret,dif_upd[x][i],dif_dwn[y][i]);
        ret=max3(ret,max_num[x][i]-now_min,now_max-min_num[y][i]);
        now_min=min(now_min,min_num[x][i]);
        now_max=max(now_max,max_num[y][i]);
        x=f[x][i];y=f[y][i];
    }
    ret=max3(ret,dif_upd[x][0],dif_dwn[y][0]);
    ret=max3(ret,max_num[x][0]-now_min,now_max-min_num[y][0]);
    now_min=min(now_min,min_num[x][0]);
    now_max=max(now_max,max_num[y][0]);
    ret=max(ret,now_max-now_min);
    return ret;
}
int main(){
    while (scanf("%d",&n)!=-1){
        Init();
        for (int i=1;i<=n;i++) w[i]=read(),fa[i]=i;
        m=read();
        for (int i=1;i<=m;i++) e[i].x=read(),e[i].y=read(),e[i].w=read();
        Kruskal();printf("%d\n",sum);

        memset(fa,0,sizeof(fa));
        deep[1]=1;BuildTree(1);
        //printf("Deep:");for (int i=1;i<=n;i++) printf("%d ",deep[i]);printf("\n");
        //for (int i=1;i<=n;i++) printf("fa[%d]=%d\n",i,fa[i]);printf("\n");

        Build();
        q=read();
        for (int i=1;i<=q;i++){
            int x=read(),y=read();
            printf("%d\n",GetAnswer(x,y));
        }
    }
    return 0;
}