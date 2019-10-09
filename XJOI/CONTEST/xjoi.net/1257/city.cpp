#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int tt=998244353;

const int maxn=200005;
const int N=200000;

int T,x,y,r;
int fac[maxn],inv[maxn];

int aabs(int x){
    return (x<0)?-x:x;
}

int qsm(int a,int b){
    int ret=1,w=a%tt;
    while (b){
        if (b&1) ret=ret*w%tt;
        b>>=1; w=w*w%tt;
    }
    return ret;
}

void build(){
    fac[0]=1;
    for (int i=1;i<=N;i++) fac[i]=fac[i-1]*i%tt;
    for (int i=0;i<=N;i++) inv[i]=qsm(fac[i],tt-2);
}

int C(int x,int y){
    return fac[x]*inv[x-y]%tt*inv[y]%tt;
}

signed main(){
    T=read();
    build();
    while (T--){
        x=aabs(read()),y=aabs(read()),r=read();
        if ((r-x-y)&1) {printf("0\n");continue;}
        int k=(r-x-y)/2;
        printf("%lld\n",C(r,k)*C(r,k+x)%tt);
    }
    return 0;
}