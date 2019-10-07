// XJOI 1255 C: COUNT

#include <bits/stdc++.h>

using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005,maxe=200005;

int n,m,a[maxn];

int tot=0,lnk[maxn],nxt[maxe],to[maxe];

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

int DFS(int now,int fa){
    int sum=0;
    for (int i=lnk[now];i;i=nxt[i]) if (to[i]!=fa) sum+=DFS(to[i],now);
    sum-=a[now];
    return max((int)0,sum);
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        add_edge(x,y);add_edge(y,x);
    }
    printf((DFS(1,-1)>0)?"No\n":"Yes\n");
    m=read();
    while (m--){
        int x=read(),y=read();
        a[x]+=y;
        printf((DFS(1,-1)>0)?"No\n":"Yes\n");
    }
    return 0;
}
