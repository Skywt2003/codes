#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int maxn=100005,maxe=200005;

int n;
int c[maxn][3];

int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int f[maxn];

int dp[maxn][3][3];
int clr[maxn];

struct node{
    int first,second,third;
};
node pre[maxn][3][3];

void add_edge(int x,int y){
    tot++; to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void make_dp(int x,int fa,int fafa){
    for (int now=0;now<3;now++)
        for (int fac=0;fac<3;fac++) if (fac!=now)
            for (int fff=0;fff<3;fff++) if (fac!=fff && fff!=now)
                if (dp[fa][fac][fff]+c[x][now] < dp[x][now][fac]){
                    dp[x][now][fac] = dp[fa][fac][fff]+c[x][now];
                    pre[x][now][fac]=(node){fa,fac,fff};
                }
    
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa) make_dp(to[i],x,fa);
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++) c[i][0]=read();
    for (int i=1;i<=n;i++) c[i][1]=read();
    for (int i=1;i<=n;i++) c[i][2]=read();

    for (int i=1;i<n;i++){
        int x=read(),y=read();
        add_edge(x,y);add_edge(y,x);
        f[x]++;f[y]++;
    }
    for (int i=1;i<=n;i++) if (f[i]>2){
        printf("-1\n");
        return 0;
    }

    int st=-1,op=-1;
    for (int i=1;i<=n;i++) if (f[i]==1){
        if (st==-1) st=i; else op=i;
    }
    memset(dp,0x3f,sizeof(dp));
    memset(dp[0],0,sizeof(dp[0]));
    make_dp(st,0,0);
    
    int ans=INF;
    node lst;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (dp[op][i][j] < ans) ans=dp[op][i][j],lst=(node){op,i,j};
    printf("%lld\n",ans);
    while (lst.first != 0){
        clr[lst.first]=lst.second;
        lst=pre[lst.first][lst.second][lst.third];
    }
    for (int i=1;i<=n;i++) printf("%lld ",clr[i]+1);
    printf("\n");
    return 0;
}