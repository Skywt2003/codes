#include<bits/stdc++.h>

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f;
const int maxn=1005,maxk=15;

const int mov[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int n,m,k;
int a[maxn][maxn];
pair<int,int> q[maxk];

int dist[maxn][maxn];
int ans=0;

queue<pair<int,int> > que;

bool check(int x,int y){
    if (x<1||y<1||x>n||y>m||a[x][y]==1) return false;
    return true;
}

void BFS(int x,int y){
    while (!que.empty()) que.pop();
    memset(dist,0x3f,sizeof(dist));
    dist[x][y]=0; que.push(make_pair(x,y));
    while (!que.empty()){
        pair<int,int> head=que.front(); que.pop();
        int xx=head.first,yy=head.second;
        for (int i=0;i<4;i++){
            int nx=xx+mov[i][0],ny=yy+mov[i][1];
            if ((!check(nx,ny)) || dist[xx][yy]+1>=dist[nx][ny]) continue;
            dist[nx][ny]=dist[xx][yy]+1;
            que.push(make_pair(nx,ny));
        }
    }
}

signed main(){
    n=read(); m=read(); k=read();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            a[i][j]=read();
    for (int i=1;i<=k;i++) q[i].first=read(),q[i].second=read(),a[q[i].first][q[i].second]=1;
    
    int xx=read(),yy=read();a[xx][yy]=1;
    for (int i=1;i<=k;i++){
        a[q[i].first][q[i].second]=0;
        BFS(xx,yy);
        a[q[i].first][q[i].second]=1;
        ans+=dist[q[i].first][q[i].second];
        if (dist[q[i].first][q[i].second]>=INF) {printf("-1\n");return 0;}
        xx=q[i].first; yy=q[i].second;
    }
    printf("%d\n",ans);
    return 0;
}