#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=1e9;

const int maxn=1006;
const int midx=500,midy=500;
const int N=10000;
const int adj[6][2]={{-2,0},{-1,2},{1,2},{2,0},{1,-2},{-1,-2}};

int T;
int a[maxn][maxn];
int cnt[6],tot=0,id[N+5];

#define xx (x+adj[i][0])
#define yy (y+adj[i][1])

void make(int x,int y){
    if (tot > N) return;
    bool vis[6]; memset(vis,0,sizeof(vis));
    for (int i=0;i<6;i++) vis[a[xx][yy]]=true;
    int now_min=INF;
    for (int i=1;i<=5;i++) if (!vis[i] && cnt[i]<now_min) now_min=cnt[i],a[x][y]=i;
    cnt[a[x][y]]++;
    id[++tot]=a[x][y];
    // printf("a[%lld][[%lld] = %lld\n",x,y,a[x][y]);
}

void build(){
    make(midx,midy);
    int sx=midx-1;
    for (int i=1;tot<=N;i++){
        int x,y;
        for (x=sx,y=midy+2*i;x>=midx-i;x-=2) make(x,y);
        x+=2;
        for (x--,y-=2;y>=midy;x--,y-=2) make(x,y);
        x++,y+=2;
        for (x++,y-=2;y>=midy-2*i;x++,y-=2) make(x,y);
        x--,y+=2;
        for (x+=2;x<=midx+i;x+=2) make(x,y);
        x-=2;
        for (x++,y+=2;y<=midy;x++,y+=2) make(x,y);
        x--,y-=2;
        for (x--,y+=2;y<=midy+2*i;x--,y+=2) make(x,y);
        sx++;
    }
}

signed main(){
    build();

    T=read();
    while (T--){
        int x=read();
        printf("%lld\n",id[x]);
    }
    return 0;
}