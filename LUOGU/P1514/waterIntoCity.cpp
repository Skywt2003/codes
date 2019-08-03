#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=(int)1<<60;
const int maxn=506;
const int shift[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int n,m;
int a[maxn][maxn];

pair<int,int> f[maxn][maxn];
bool vis[maxn][maxn];

bool check(int x,int y){
    return !(x<1||y<1||x>n||y>m);
}

void merge(int x,int y,int xx,int yy){
    f[x][y].first =min(f[x][y].first ,f[xx][yy].first ); 
    f[x][y].second=max(f[x][y].second,f[xx][yy].second);
}

#define nx (x+shift[i][0])
#define ny (y+shift[i][1])

void make_interval(int x,int y){
    if (vis[x][y]) return;
    vis[x][y]=true;
    if (x==n) f[x][y]=make_pair(y,y);
    for (int i=0;i<4;i++) if (check(nx,ny) && a[x][y]>a[nx][ny]){
        make_interval(nx,ny);
        merge(x,y,nx,ny);
    }
}

bool compare_first(pair<int,int> aa,pair<int,int> bb){
    return aa.first < bb.first;
}

int dp[maxn];

signed main(){
    n=read();m=read();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            a[i][j]=read(),f[i][j]=make_pair(INF,0);

    for (int i=1;i<=m;i++) make_interval(1,i);

    int cnt=0;
    for (int i=1;i<=m;i++) if (!vis[n][i]) cnt++;
    if (cnt){
        printf("0\n%lld\n",cnt);
        return 0;
    }

    printf("1\n");
    // for (int i=1;i<=m;i++) printf("%lld %lld\n",f[1][i].first,f[1][i].second);
    memset(dp,63,sizeof(dp));
    sort(f[1]+1,f[1]+1+m,compare_first);
    for (int i=1;i<=m;i++) if (f[1][i].first==1) dp[i]=1;
    for (int i=1;i<=m;i++){
        for (int j=1;j<i;j++){
            if (f[1][j].second+1 >= f[1][i].first) dp[i]=min(dp[i],dp[j]+1);
        }
    }
    int ans=INF;
    for (int i=1;i<=m;i++) if (f[1][i].second==m) ans=min(ans,dp[i]);
    printf("%lld\n",ans);
    return 0;
}