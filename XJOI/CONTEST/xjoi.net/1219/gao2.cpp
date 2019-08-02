#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int tt=1000000009;

const int maxn=1005,maxk=15;
const int N=1000,K=10;

int n,k;
int f[maxn][maxk],pre[maxn][maxk];

int c4(int x){
    if (x==4) return 1;
    if (x==1 || x==3) return 4; else
    if (x==2) return 6;
}

signed main(){
    f[0][0]=1;
    for (int k=1;k<=N;k++){
        for (int i=N;i>=0;i--)
            for (int j=K;j>=0;j--)
                pre[i][j]=f[i][j];

        for (int num=1;num<=4;num++)
            for (int i=N;i>=num*k;i--)
                for (int j=K;j>=num;j--)
                    f[i][j]=(f[i][j]+pre[i-num*k][j-num]*c4(num)%tt)%tt;
    }
    n=read();k=read();
    while (n!=0 || k!=0){
        int ans=0;
        for (int i=1;i<=k;i++) ans=(ans+f[n][i])%tt;
        printf("%lld\n",ans);
        n=read();k=read();
    }
    return 0;
}