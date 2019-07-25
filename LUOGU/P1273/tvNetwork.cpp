#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=3005,maxe=6005;
const int INF=(int)1<<60;

int n,m,p[maxn];
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];

int f[maxn][maxn];
int cnt[maxn];

void add_edge(int x,int y,int z){
    tot++;to[tot]=y;w[tot]=z;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void make_dp(int x){
    if (x>n-m){
        cnt[x]=1;
        f[x][1]=p[x];
        return;
    }
    for (int i=lnk[x];i;i=nxt[i]){
        make_dp(to[i]);
        cnt[x]+=cnt[to[i]];
        for (int j=m;j>=1;j--)
            for (int k=0;k<=min(j,cnt[to[i]]);k++)
                f[x][j]=max(f[x][j],f[x][j-k]+f[to[i]][k]-w[i]);
    }
}

signed main(){
    fill(f[0],f[0]+maxn*maxn,-INF);
    n=read();m=read();
    for (int i=1;i<=n-m;i++){
        int sons=read();
        while (sons--){
            int x=read(),y=read();
            add_edge(i,x,y);
        }
    }
    for (int i=1;i<=m;i++) p[n-m+i]=read();

    for (int i=1;i<=n;i++) f[i][0]=0;
    make_dp(1);

    for (int i=m;i>=1;i--) if (f[1][i]>=0){
        printf("%lld\n",i);
        return 0;
    }
    return 0;
}