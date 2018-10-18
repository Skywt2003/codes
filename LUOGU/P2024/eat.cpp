#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,m,fa[maxn],rank[maxn],ans=0;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline int getfa(int x){
    if (fa[x]==x) return x;
    int f=fa[x];
    fa[x]=getfa(fa[x]); //路径压缩
    rank[x]=(rank[x]+rank[f])%3;
    return fa[x];
}
inline bool check(int k,int x,int y){
    if (x>n||y>n) return false;
    if (k==2&&x==y) return false;
    int fx=getfa(x),fy=getfa(y);
    if (k==1){
        if (fx==fy){
            if (rank[x]!=rank[y]) return false;
        } else {
            fa[fx]=fy;
            rank[fx]=(rank[y]-rank[x]+3)%3;
            getfa(x);getfa(y);
        }
    } else {
        if (fx==fy){
            if (rank[x]==1&&rank[y]!=0) return false;
            if (rank[x]==2&&rank[y]!=1) return false;
            if (rank[x]==0&&rank[y]!=2) return false;
        } else {
            fa[fx]=fy;
            rank[fx]=(rank[y]-rank[x]+3+1)%3;
            getfa(x);getfa(y);
        }
    }
    return true;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=m;i++){
        int z=read(),x=read(),y=read();
        if (!check(z,x,y)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}