#include<bits/stdc++.h>
using namespace std;

#define sqr(_) ((_)*(_))

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

char read_char(){
    char ch=getchar();
    while (ch!='0'&&ch!='1') ch=getchar();
    return ch;
}

const int maxn=155,maxe=150*150+5;
const double INF=1e9;

int n,x[maxn],y[maxn];
double ans=INF;

int tot=0,lnk[maxn],nxt[maxe],to[maxe];
double w[maxe];

double g[maxn][maxn],dist[maxn];

double get_dist(int i,int j){
    return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}

bool vis[maxn];
queue <int> que;

void SPFA(int s){
	while (!que.empty()) que.pop();
	fill(dist,dist+maxn,INF);
	memset(vis,0,sizeof(vis));

	que.push(s); vis[s]=true; dist[s]=0.0;
	while (!que.empty()){
		int head=que.front(); que.pop();
		vis[head]=false;
		for (int i=1;i<=n;i++) if (g[head][i]!=INF && dist[head]+g[head][i]<dist[i]){
            dist[i]=dist[head]+g[head][i];
            if (!vis[i]) que.push(i),vis[i]=true;
        }
	}
}

int fa[maxn];

int getfa(int x){
    if (fa[x]==x) return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}

void merge(int x,int y){
    x=getfa(x),y=getfa(y);
    if (x==y) return;
    fa[x]=y;
}

double get_diameter(int s){
    SPFA(s);
    double max_num=0.0,k=-1;
    for (int i=1;i<=n;i++) if (dist[i]!=INF && dist[i]>max_num) max_num=dist[i],k=i;
    SPFA(k); max_num=0.0;
    for (int i=1;i<=n;i++) if (dist[i]!=INF) max_num=max(max_num,dist[i]);
    return max_num;
}

signed main(){
    freopen("testdata.in","r",stdin);
    n=read();
    for (int i=1;i<=n;i++) x[i]=read(),y[i]=read(),fa[i]=i;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            g[i][j]=(read_char()=='1')?get_dist(i,j):INF;
            if (g[i][j]!=INF) merge(i,j);
        }

    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++) if (g[i][j]==INF && getfa(i)!=getfa(j)){
            g[i][j]=g[j][i]=get_dist(i,j);
            ans=min(ans,get_diameter(i));
            g[i][j]=g[j][i]=INF;
        }

    printf("%.6lf\n",ans);
    return 0;
}