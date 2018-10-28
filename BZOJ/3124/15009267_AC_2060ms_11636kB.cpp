#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=200005,maxe=2*maxn;
int n,lnk[maxn],nxt[maxe],son[maxe],w[maxe],tot=0,rson[maxn],L,R;
bool vis[maxn],hpd[maxn]; // hpd[x]:(Happend) 表示从x出发是否有多于一条最长路
long long dst[maxn],len;
inline void add(int x,int y,int z){tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;}
inline void Clear(){memset(dst,0,sizeof(dst));memset(vis,0,sizeof(vis));memset(hpd,0,sizeof(hpd));memset(rson,0,sizeof(rson));}
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline int Find(int x){ // 寻找能走到的最远点
    vis[x]=1;
    int ret=x;
    long long dst_now=dst[x];
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]){
        dst[son[i]]=dst[x]+w[i];
        int now=Find(son[i]);
        if (dst[now]>dst_now) hpd[x]=false,dst_now=dst[now],ret=now,rson[x]=son[i]; else // Rson (Real Son) 数组用来记录直径
        if (dst[now]==dst_now) hpd[x]=true;
    }
    return ret;
}
inline void Pass(int x,int y,bool LorR){
    while (x!=y){
        if (hpd[x]) {if (LorR) R=x; else L=x;return;}
        x=rson[x];
    }
    if (LorR) R=Find(y); else L=Find(x);
}
inline int GetAnswer(int x,int y){
    int ret=0;
    while (x!=y){
        ret++;
        x=rson[x];
    }
    return ret;
}
int main(){
    n=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read(),z=read();
        add(x,y,z);add(y,x,z);
    }
    Clear();int s=Find(1);
    Clear();int t=Find(s);len=dst[t];
    printf("%lld\n",len);
    Pass(s,t,0);
    Clear();Find(t);
    Pass(t,s,1);
    Clear();Find(L);
    printf("%d\n",GetAnswer(L,R));
    return 0;
}
