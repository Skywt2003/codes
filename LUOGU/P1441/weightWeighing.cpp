#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=25,maxv=2005;

int n,m,allv=0,ans=0;
int a[maxn];
bool f[maxv],vis[maxn];

void DFS(int x,int cnt){
    if (cnt==m){
        memset(f,0,sizeof(f));
        f[0]=true;
        for (int i=1;i<=n;i++) if (!vis[i])
            for (int j=allv;j>=a[i];j--)
                f[j]|=f[j-a[i]];
        int now=0;
        for (int i=1;i<=allv;i++) now+=f[i];
        ans=max(ans,now);
        return;
    } else if (n-x < m-cnt) return;
    vis[x+1]=true;
    DFS(x+1,cnt+1);
    vis[x+1]=false;
    DFS(x+1,cnt);
}

signed main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) a[i]=read(),allv+=a[i];

    DFS(0,0);

    printf("%d\n",ans);
    return 0;
}