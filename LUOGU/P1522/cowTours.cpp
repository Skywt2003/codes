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

const int maxn=155;
const double INF=1e9;

int n,x[maxn],y[maxn];
double ans1=0,ans2=INF;

double lnk[maxn][maxn],dist[maxn];
double farway[maxn];

double get_dist(int i,int j){
    return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}

void Floyd(){
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++) if (i!=k && lnk[i][k]!=INF)
            for (int j=1;j<=n;j++) if (k!=j && lnk[k][j]!=INF && i!=j)
                lnk[i][j]=min(lnk[i][j],lnk[i][k]+lnk[k][j]);
}

void make_farway(){
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (lnk[i][j]!=INF) farway[i]=max(farway[i],lnk[i][j]);
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            lnk[i][j]=(read_char()=='1')?get_dist(i,j):INF;
    for (int i=1;i<=n;i++) lnk[i][i]=0.0;

    Floyd();
    make_farway();
    for (int i=1;i<=n;i++) ans1=max(ans1,farway[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) if (lnk[i][j]==INF)
            ans2=min(ans2,farway[i]+farway[j]+get_dist(i,j));

    printf("%.6lf\n",max(ans1,ans2));
    return 0;
}