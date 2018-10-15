#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10005;
int n,m,w[maxn],v[maxn];
double ans,q[maxn];
inline bool cmp(double x,double y){
    return x>y;
}
inline bool check(double x){
    for (int i=1;i<=n;i++) q[i]=(double)v[i]-(double)w[i]*x;
    sort(q+1,q+1+n,cmp);
    double cnt=0.0;
    for (int i=1;i<=m;i++) cnt+=q[i];
    return cnt>=0.0;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&w[i]);
    for (int i=1;i<=n;i++) scanf("%d",&v[i]);
    double L=1e-8,R=1e8;
    while (R-L>1e-5){
        double mid=(L+R)/2.0;
        if (check(mid)){
            ans=mid;L=mid+1e-5;
        } else R=mid-1e-5;
    }
    printf("%.2f\n",ans);
    return 0;
}