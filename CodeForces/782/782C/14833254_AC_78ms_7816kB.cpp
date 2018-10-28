#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=200005,maxe=400005;
int n,tot=0,ans=0,lnk[maxn],son[maxe],nxt[maxe],clr[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void add(int x,int y){
    tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void DFS(int x,int lst){
    int now_color=0;
    for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=lst){
        now_color++;
        while (now_color==clr[x]||(lst!=-1&&now_color==clr[lst])) now_color++;
        clr[son[i]]=now_color;
        DFS(son[i],x);
    }
    ans=max(ans,now_color);
}
int main(){
    memset(clr,255,sizeof(clr));
    n=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    clr[1]=1;
    DFS(1,-1);
    printf("%d\n",ans);
    for (int i=1;i<=n;i++) printf("%d ",clr[i]);
    printf("\n");
    return 0;
}
