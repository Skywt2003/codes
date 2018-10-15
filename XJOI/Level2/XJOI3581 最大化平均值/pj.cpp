// Dinkelbach Iterative ALgorithm
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=500005;
const double eps=1e-7;
int n,m,w[maxn],v[maxn];
struct TempData{
    double x;
    int id;
}a[maxn];
double ans=1e7;
inline double myabs(double x){
    if (x<0) return -x; else return x;
}
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline bool cmp(TempData aa,TempData bb){
    return aa.x>bb.x;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) w[i]=read();
    for (int i=1;i<=n;i++) v[i]=read();
    double now=(double)(rand()%n);
    while (myabs(now-ans)>eps){
        ans=now;
        for (int i=1;i<=n;i++) a[i].x=(double)v[i]-(double)w[i]*ans,a[i].id=i;
        sort(a+1,a+1+n,cmp);
        double sum_w=0.0,sum_v=0.0;
        for (int i=1;i<=m;i++){
            sum_w+=w[a[i].id];
            sum_v+=v[a[i].id];
        }
        now=sum_v/sum_w;
    }
    printf("%.2f\n",ans);
    return 0;
}