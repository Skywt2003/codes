#include<bits/stdc++.h>
#define sqr(_) ((_)*(_))
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005;

double a,b,d;
int n;
struct dot{
    double x,y,value;
};
dot dots[maxn];

int ans=0;

bool cmp(dot aa,dot bb){
    return aa.value > bb.value;
}

double myabs(double x){
    return (x<0)?-x:x;
}

double get_distance(double x,double y,double k,double b){
    double x1=(x-k*b+k*y)/(k*k+1);
    double y1=k*x1+b;
    return sqrt(sqr(x-x1)+sqr(y-y1));
}

signed main(){
    scanf("%lf%lf%lf",&a,&b,&d); n=read();
    for (int i=1;i<=n;i++){
        scanf("%lf%lf",&dots[i].x,&dots[i].y);
        dots[i].value=a*dots[i].x/b+dots[i].y;
    }

    sort(dots+1,dots+1+n,cmp);
    int head=1,tail=1;
    for (int i=1;i<=n;i++){
        double nowb=a*dots[head].x/b+dots[head].y;
        while (tail+1<=n && get_distance(dots[tail+1].x,dots[tail+1].y,-a/b,nowb) <= 2.0*d) tail++;
        ans=max(ans,tail-head+1);
        head++;
    }
    printf("%d\n",ans);
    return 0;
}