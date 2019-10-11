#include<bits/stdc++.h>
// #define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=5005;

int n,v[maxn],sum[maxn];

double fsum1[maxn],fsum2[maxn];
double ans;

signed main(){
    n=read();
    for (int i=1;i<=n;i++) v[i]=read(),sum[i]=sum[i-1]+v[i];

    for (int L=2;L<=n;L++){
        for (int i=1;i<=n-L+1;i++){
            int j=i+L-1;
            double now=(fsum1[i]+fsum2[j])/(j-i)+(sum[j]-sum[i-1]);
            fsum1[i]+=now; fsum2[j]+=now;
            if (i==1 && j==n) ans=now;
        }
    }
    printf("%.5lf\n",ans);
    return 0;
}