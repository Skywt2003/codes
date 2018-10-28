#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=15,maxe=405,maxx=59100;
int n,m,s,INF,tot=0,f[maxx][maxn],lnk[maxe],nxt[maxe],son[maxe],w[maxe],sqr[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void add(int x,int y,int z){
    tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void Init(){
    tot=0;
    memset(lnk,0,sizeof(lnk));
    memset(nxt,0,sizeof(nxt));
    memset(son,0,sizeof(son));
    memset(w,0,sizeof(w));
    memset(f,63,sizeof(f));INF=f[0][0];
}
inline void BuildSquare(){
    int x=1;
    for (int i=0;i<11;i++) sqr[i]=x,x=x*3;
}
inline int check(int x,int y){
    for (int t=0;t<y;t++) x/=3;
    return x%3;
}
inline bool AllVisited(int x){
    int cnt=0;
    while (x){
        cnt++;
        if (x%3==0) return false;
        x/=3;
    }
    if (cnt!=n) return false;
    return true;
}
int main(){
    BuildSquare();
    while (scanf("%d%d",&n,&m)!=-1){
        s=sqr[n];
        Init();
        for (int i=0;i<m;i++){
            int x=read(),y=read(),z=read();
            add(x-1,y-1,z);add(y-1,x-1,z);
        }
        for (int i=0;i<n;i++) f[sqr[i]][i]=0;
        for (int j=1;j<s;j++)
        for (int i=0;i<n;i++) if (check(j,i)>0){
            for (int k=lnk[i];k;k=nxt[k]) if (i!=son[k]&&check(j,son[k])>0) f[j][i]=min(f[j][i],f[j-sqr[i]][son[k]]+w[k]);
        }
        int ans=1<<30,dyn=0;
        for (int i=0;i<n;i++) dyn+=sqr[i];
        // printf("DYN=%d\n",dyn);
        for (int j=dyn;j<s;j++) if (AllVisited(j))
        for (int i=0;i<n;i++) if (f[j][i]<ans) ans=f[j][i];
        if (ans==INF) printf("-1\n"); else printf("%d\n",ans);
    }
    return 0;
}