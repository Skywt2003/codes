// F[i]: 前 i 节课不知道上了几节，其中最后一节课必上，最大做作业数量
// G[i][j]: i 的时间，j 的能力，能做作业数量

#include<bits/stdc++.h>

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f;
const int maxm=1005,maxn=100005;
const int maxt=100005,maxq=105;

int t,n,m;

struct lesson{
    int s,t,p;
};

struct homework{
    int t,q;
};

bool compare_homework_q(homework aa,homework bb){
    return aa.q < bb.q;
}

lesson a[maxm];
homework b[maxn];

int f[maxm];
int g[maxt][maxq];

signed main(){
    t=read()+1; m=read(); n=read();
    for (int i=1;i<=m;i++){
        a[i].s=read(),a[i].t=read(),a[i].p=read();
    }
    a[0]=(lesson){1,0,1};
    a[++m]=(lesson){t+1,0,1};
    for (int i=1;i<=n;i++){
        b[i].t=read(),b[i].q=read();
    }

    sort(b+1,b+1+n,compare_homework_q);
    int k=0,tmin=INF;
    for (int j=0;j<=100;j++)
        for (int i=1;i<=t;i++){
            while (k+1<=n && b[k+1].q<=j) k++,tmin=min(tmin,b[k].t);
            g[i][j]=i/tmin;
        }

    for (int i=1;i<=m;i++){
        for (int j=0;j<i;j++){
            int now=a[i].s-(a[j].s+a[j].t);
            if (now<=0) continue;
            f[i]=max(f[i],f[j]+g[now][a[j].p]);
        }
    }
    printf("%d\n",f[m]-1);
    return 0;
}