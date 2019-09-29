#include<bits/stdc++.h>

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=305;

int n,m,q;
int c[maxn];
int ans[maxn][maxn];
int dist[maxn][maxn];

pair<int,int> shuf[maxn];

void Floyd(){
    for (int t=1;t<=n;t++){
        int k=shuf[t].second;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                ans[i][j]=min(ans[i][j],dist[i][j]+max(max(c[i],c[j]),c[k]));
            }
    }
}

bool compare_first(pair<int,int> aa,pair<int,int> bb){
    return aa.first < bb.first;
}

signed main(){
    n=read();m=read();
    memset(ans,0x3f,sizeof(ans));
    memset(dist,0x3f,sizeof(dist));
    for (int i=1;i<=n;i++) dist[i][i]=ans[i][i]=0;

    for (int i=1;i<=n;i++) c[i]=read(),shuf[i]=make_pair(c[i],i);
    sort(shuf+1,shuf+1+n,compare_first);

    for (int i=1;i<=m;i++){
        int x=read(),y=read(),w=read();
        dist[x][y]=dist[y][x]=min(dist[x][y],w);
    }

    Floyd();

    q=read();
    while (q--){
        int x=read(),y=read();
        printf("%d\n",ans[x][y]);
    }
    return 0;
}