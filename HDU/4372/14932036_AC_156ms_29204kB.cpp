#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=2005,tt=1e9+7;
int T,n,a,b,f[maxn][maxn],c[maxn][maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void MakeDP(){
//    for (int i=0;i<=2000;i++) f[i][0]=1;
    f[1][1]=1;
    for (int i=2;i<=2000;i++)
        for (int j=1;j<=i;j++)
            f[i][j]=((long long)f[i-1][j-1]+(long long)(i-1)*f[i-1][j]%tt)%tt;
    for (int i=0;i<=2000;i++) c[i][0]=1;
    for (int i=1;i<=2000;i++){
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%tt;
    }
}
int main(){
    T=read();
    MakeDP();
    while (T--){
        n=read();a=read();b=read();
        if (a+b-2>2000){printf("0\n");continue;}
        printf("%lld\n",(long long)f[n-1][a-1+b-1]*c[a-1+b-1][a-1]%tt);
    }
    return 0;
}
