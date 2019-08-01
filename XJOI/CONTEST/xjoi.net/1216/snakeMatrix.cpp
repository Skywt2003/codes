#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=3005;
const int tt=1e9+7;

int xx,n=1;
int a[maxn][maxn],sum[maxn][maxn];
int nx,ny;
int now=0;

void check(int x,int y){
    if (now==xx) nx=x,ny=y;
}

signed main(){
    xx=read();

    int s=1,t=1,delta=0;
    while (t<xx){
        s=t+1; delta+=2; t=s+delta;
        n++;
    }

    bool flg=1; // flg=1: right up;  flg=2:down left
    for (int k=1;k<=n;k++){
        if (flg){
            for (int i=1;i<k;i++) a[k][i]=++now,check(k,i);
            a[k][k]=++now;check(k,k);
            for (int i=1;i<k;i++) a[k-i][k]=++now,check(k-i,k);
        } else {
            for (int i=1;i<k;i++) a[i][k]=++now,check(i,k);
            a[k][k]=++now;check(k,k);
            for (int i=1;i<k;i++) a[k][k-i]=++now,check(k,k-i);
        }
        flg=!flg;
    }

    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++){
        sum[i][j]=(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j]+tt)%tt;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) printf("%lld ",sum[i][j]);
        printf("\n");
    }
    int ans=0;
    for (int i=1;i<=nx;i++)
    for (int j=1;j<=ny;j++)
        ans=(ans+sum[i][j])%tt;

    printf("%lld\n",ans);
    return 0;
}