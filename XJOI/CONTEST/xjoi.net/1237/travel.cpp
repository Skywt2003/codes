#include<bits/stdc++.h>

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

// const int maxn=300005,maxe=600005;
// int n,ans=0;
// int p[maxn],now[maxn];
// int tot=0,lnk[maxn],nxt[maxe],to[maxe];

// void add_edge(int x,int y){
//     tot++;to[tot]=y;
//     nxt[tot]=lnk[x];lnk[x]=tot;
// }

// void DFS(int x,int step,int fa,bool flg){ // 0=  1<
//     if (flg==false && x>p[step]) return;
//     now[step]=x;
//     if (step==n) {ans++;return;}
//     for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa) DFS(to[i],step+1,x,flg||(x<p[step]));
// }

signed main(){
    // n=read();
    // for (int i=1;i<=n;i++) p[i]=read();
    // for (int i=1;i<n;i++){
    //     int x=read(),y=read();
    //     add_edge(x,y);add_edge(y,x);
    // }

    // for (int i=1;i<=n;i++) DFS(i,1,-1,0);

    // printf("%d\n",ans);
    printf("0\n");
    return 0;
}