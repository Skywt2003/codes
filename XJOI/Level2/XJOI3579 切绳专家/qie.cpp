#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=10005;
int n,m;
char s[100];
double a[maxn],sum=0.0,ans=0.0;
inline bool check(double x){
    int cnt=0;
    for (int i=1;i<=n;i++) cnt+=trunc(a[i]/x);
    return cnt>=m;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){scanf("%lf",&a[i]);sum+=a[i];}
    double L=0.0,R=sum+1.0,mid;
    while (R-L>1e-4){
        double mid=(L+R)/2.0;
        if (mid==0.0) break;
        if (check(mid)){
            ans=mid;
            L=mid;
        } else R=mid;
    }
    sprintf(s+1,"%.3f",ans);
    s[strlen(s+1)]='\0';
    printf("%s",s+1);
    return 0;
}
