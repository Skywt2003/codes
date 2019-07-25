#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=5e5+5,maxe=1e6+5;

int n;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
double w[maxe],q[maxn];
double f[maxn],g[maxn];

void addEdge(int x,int y,double z){
    tot++;to[tot]=y;w[tot]=z;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void buildFArr(int x,int fa){
    f[x]=1.0;
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
        buildFArr(to[i],x);
        f[x]*=((1.0-w[i])+w[i]*(1.0-q[to[i]])*f[to[i]]);
    }
}

void buildGArr(int x,int fa,int wfa){
    if (wfa!=-1) g[x]=(1.0-w[wfa])+w[wfa]*(1.0-q[fa])*f[fa]*g[fa]/((1.0-w[wfa])+w[wfa]*(1.0-q[x])*f[x]);
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa) buildGArr(to[i],x,i);
}

signed main(){
    n=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read(),z=read();
        addEdge(x,y,(double)z/100);addEdge(y,x,(double)z/100);
    }
    for (int i=1;i<=n;i++) q[i]=(double)read()/100;
    buildFArr(1,-1);
    g[1]=1.0;
    buildGArr(1,-1,-1);
    double ans=0.0;
    for (int i=1;i<=n;i++) ans+=(1.0-f[i]*g[i]*(1.0-q[i]));
    printf("%.6lf\n",ans);
    return 0;
}