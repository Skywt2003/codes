#include<bits/stdc++.h>

using namespace std;

// #define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005;
const int tt=10007;

int a,b,k,n,m;
int c[maxn][maxn];
int ans=0;

void build(){
    c[1][1]=c[1][2]=1;
    for (int i=2;i<=k;i++){
        c[i][1]=c[i][i+1]=1;
        for (int j=2;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%tt;
    }
}

int qsm(int a,int b){
    int ret=1,w=a%tt;
    while (b){
        if (b&1) ret=ret*w%tt;
        b>>=1; w=w*w%tt;
    }
    return ret;
}

signed main(){
    a=read(); b=read(); k=read(); n=read(); m=read();

    build();
    ans=qsm(a,n)*qsm(b,m)%tt*c[k][m+1]%tt;
    printf("%d\n",ans);
    return 0;
}