/*
 * 最变态的情形是不存在的，直接最小生成树
 * 逼着你写 Prim
 */

#include<bits/stdc++.h>
using namespace std;

#define sqr(_) ((_)*(_))

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=5005;
double INF=1.0e10;

int n;
double x[maxn],y[maxn];
double ans=0.0;

double get_distance(int i,int j){
    return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}

double lowcast[maxn];

void Prim(){
    lowcast[1]=-1.0;
    for (int i=2;i<=n;i++) lowcast[i]=get_distance(1,i);
    for (int i=1;i<n;i++){
        double now_min=INF; int k=-1;
        for (int j=1;j<=n;j++) if (lowcast[j]!=-1.0 && lowcast[j]<now_min) now_min=lowcast[j],k=j;
        ans+=lowcast[k]; lowcast[k]=-1.0;
        for (int j=1;j<=n;j++) if (lowcast[j]!=-1.0) lowcast[j]=min(lowcast[j],get_distance(k,j));
    }
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
    Prim();
    printf("%.2lf\n",ans);
    return 0;
}