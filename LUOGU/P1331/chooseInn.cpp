#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=200005,maxc=55;

int n,k,p;
int a[maxn],b[maxn];
int cof[maxn],sum[maxn][maxc];
int ans=0;

signed main(){
    n=read(); k=read(); p=read();
    for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();

    for (int i=n;i>=1;i--)
        for (int j=0;j<k;j++)
            sum[i][j]=sum[i+1][j]+(a[i]==j);
    cof[n+1]=-1;
    for (int i=n;i>=1;i--)
        if (b[i]<=p) cof[i]=i; else cof[i]=cof[i+1];
    
    for (int i=1;i<=n;i++) if (cof[i]!=-1)
        ans+=sum[cof[i]+(cof[i]==i)][a[i]];
    
    printf("%lld\n",ans);
    return 0;
}