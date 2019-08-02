#include<bits/stdc++.h>
// #define int long long
using namespace std;

#define sqr(_) ((_)*(_))

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=506,maxe=250005;

int n,s;
int x[maxn],y[maxn];

double get_distance(int i,int j){
    return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}

struct edge{
    int x,y;
    double w;
};
edge make_edge(int x,int y,double w){
    edge ret; ret.x=x;ret.y=y;ret.w=w;
    return ret;
}

vector<edge> vec;

int fa[maxn];

void init(int n){
    for (int i=1;i<=n;i++) fa[i]=i;
}

int getfa(int x){
    if (fa[x]==x) return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}

bool compare_weight(edge aa,edge bb){
    return aa.w<bb.w;
}

double ans=0.0;

void Kruscal(){
    init(n);
    sort(vec.begin(),vec.end(),compare_weight);
    int cnt=0;
    for (int i=0;i<(int)vec.size();i++){
        int fx=getfa(vec[i].x),fy=getfa(vec[i].y);
        if (fx==fy) continue;
        fa[fx]=fy; cnt++; ans=max(ans,vec[i].w);
        if (cnt==n-s) return;
    }
}

void build_edges(){
    for (int i=1;i<=n;i++)
    for (int j=i+1;j<=n;j++)
        vec.push_back(make_edge(i,j,get_distance(i,j)));
}

signed main(){
    s=read();n=read();
    for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
    build_edges();
    Kruscal();
    printf("%.2lf\n",ans);
    return 0;
}