// XJOI 1254 B

#include <bits/stdc++.h>

using namespace std;
//#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=50005;
const int maxn2=1000005;

int n,cnt=0;
pair<int,int> a[maxn];
double ac[maxn2];

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i].first=read(),a[i].second=read();

    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++){
            if (a[i].first == a[j].first) {ac[++cnt]=acos(0);continue;}
            double k=(double)(a[j].second-a[i].second)/(a[j].first-a[i].first);
            double x=(k<0)?-1.0:1.0;
            ac[++cnt]=acos(x/sqrt(k*x*k*x+x*x));
            // printf("%.2lf\n -> %.2lf\n",k,ac[cnt]);
        }
    sort(ac+1,ac+1+cnt);
    if (cnt&1) printf("%.13lf\n",ac[(cnt+1)/2]); else printf("%.13lf\n",(ac[cnt/2]+ac[cnt/1+2])/2);
    return 0;
}
