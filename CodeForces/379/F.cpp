#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1500005;
int n=0,q,x1,x2,dd,deep[maxn],fa[maxn],f[maxn][26];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void Build(int x){
    f[x][0]=fa[x];
    for (int i=1;i<25;i++) f[x][i]=f[f[x][i-1]][i-1];
}
inline int GetDistance(int x,int y){
    int ret=0;
    if (deep[x]<deep[y]) swap(x,y);
    for (int i=24;i>=0;i--) if (deep[f[x][i]]>=deep[y]) x=f[x][i],ret+=1<<i;
    if (x==y) return ret;
    for (int i=24;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i],ret+=1<<i<<1;
    return ret+2;
}
int main(){
    q=read();n=4;
    fa[2]=fa[3]=fa[4]=1;
    f[2][0]=f[3][0]=f[4][0]=1;
    deep[1]=1;
    deep[2]=deep[3]=deep[4]=2;
    x1=2;x2=4;dd=2;
    for (int i=1;i<=q;i++){
        int x=read();
        fa[++n]=x;fa[++n]=x;
        deep[n-1]=deep[n]=deep[x]+1;
        Build(n-1);Build(n);
        int xx1=x1,xx2=x2;

        int d1=GetDistance(n-1,xx1),d2=GetDistance(n-1,xx2);
        if (d1>dd) x2=n-1,dd=d1;
        if (d2>dd) x1=n-1,dd=d2;

        d1=GetDistance(n,xx1),d2=GetDistance(n,xx2);
        if (d1>dd) x2=n,dd=d1;
        if (d2>dd) x1=n,dd=d2;

        printf("%d\n",dd);
    }
    return 0;
}
