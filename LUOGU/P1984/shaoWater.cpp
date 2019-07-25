#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=3000005;
int n;
double ans;

signed main(){
    n=read();
    double now=420000.0/n;
    for (int i=1;i<=n;i++) ans+=now,now*=(1-0.5/i);
    printf("%.2lf\n",ans);
    return 0;
}