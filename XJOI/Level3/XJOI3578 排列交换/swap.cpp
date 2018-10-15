#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,m,a[maxn],fa[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline int getfa(int x){
    if (fa[x]==x) return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}
inline void merge(int x,int y){
    int fx=getfa(x),fy=getfa(y);
    if (fx!=fy) fa[fx]=fy;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) a[i]=read(),fa[i]=i;
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        merge(a[x],a[y]);
    }
    int ans=0;
    for (int i=1;i<=n;i++) if (getfa(a[i])==getfa(i)) ans++;
    printf("%d\n",ans);
    return 0;
}