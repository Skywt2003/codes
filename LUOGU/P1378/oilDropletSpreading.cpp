#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

#define sqr(_) ((_)*(_))

const int maxn=10;
const double INF=1.0e9;
const double pi=3.1415926;
int n,xx1,yy1,xx2,yy2;
int x[maxn],y[maxn];

int a[maxn];
bool vis[maxn];
double spt[maxn];
double ans=0;

double get_distance(int i,int j){
    return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}

void DFS(int xx){
    if (xx==n){
        fill(spt,spt+maxn,0.0);
        double sum=0.0,now;
        for (int i=1;i<=n;i++){
            now=(double)min(min(x[a[i]]-xx1,xx2-x[a[i]]),min(y[a[i]]-yy1,yy2-y[a[i]]));
            for (int k=1;k<i;k++) if (spt[a[k]]!=0.0) now=min(now,get_distance(a[i],a[k])-spt[a[k]]);
            if (now<0.0) continue;
            sum+=now*now*pi; spt[a[i]]=now;
        }
        ans=max(ans,sum);
        return;
    }
    for (int i=1;i<=n;i++) if (!vis[i]){
        vis[i]=true;
        a[xx+1]=i;
        DFS(xx+1);
        vis[i]=false;
    }
}

signed main(){
    freopen("testdata.in","r",stdin);
    freopen("my.out","w",stdout);
    n=read();
    xx1=read(),yy1=read(),xx2=read(),yy2=read();
    if (xx1>xx2) swap(xx1,xx2);
    if (yy1>yy2) swap(yy1,yy2);
    for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();

    DFS(0);
    // printf("%d\n",(int)round(ans));
    ans=round(1.0*(xx2-xx1)*1.0*(yy2-yy1)-ans);
    printf("%d\n",(int)ans);
    return 0;
}