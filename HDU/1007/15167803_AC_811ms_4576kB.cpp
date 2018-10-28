#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=200005;
const double INF=1.0e8;
int n;
struct PointInfo{
    double x,y;
};
PointInfo a[maxn],que[maxn];
inline bool cmp(PointInfo aa,PointInfo bb){
    return aa.x<bb.x;
}
inline bool cmpy(PointInfo aa,PointInfo bb){
    return aa.y<bb.y;
}
inline double GetDist(PointInfo aa,PointInfo bb){
    return sqrt((double)(aa.x-bb.x)*(aa.x-bb.x)+(double)(aa.y-bb.y)*(aa.y-bb.y));
}
inline double Make(int L,int R){
    double ret=INF;
    if (L>=R) return ret;
    if (R==L+1) return GetDist(a[L],a[R]);
    int mid=((R-L)>>1)+L;
    ret=min(Make(L,mid),Make(mid+1,R));
    int i=mid,j=mid,cnt=0;
    que[++cnt].x=a[mid].x;
    que[cnt].y=a[mid].y;
    while (i-1>=L && (double)a[mid].x-a[i-1].x<ret) i--,que[++cnt].x=a[i].x,que[cnt].y=a[i].y;
    while (j+1<=R && (double)a[j+1].x-a[mid].x<ret) j++,que[++cnt].x=a[j].x,que[cnt].y=a[j].y;
    sort(que+1,que+1+cnt,cmpy);
    for (int i=1;i<=cnt;i++){
        int j=i;
        while (j+1<=cnt && que[j+1].y-que[i].y<ret) j++,ret=min(ret,GetDist(que[i],que[j]));
    }
    return ret;
}
int main(){
    while (1){
        scanf("%d",&n);
        if (n==0) break;
        for (int i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
        sort(a+1,a+1+n,cmp);
        printf("%.2lf\n",Make(1,n)/2.0);
    }
    return 0;
}