#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=2005,tt=1000000007;
int n,a[maxn],f[maxn],fac[maxn],inv[maxn],num_a=0,num_b=0;
bool vis[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void Init(){
    int n=2000;
//    inv[1]=1;
//    for (int i=2;i<=n;i++) inv[i]=(long long)(tt-tt/i)*inv[tt%i]%tt;
    fac[0]=1;
    for (int i=1;i<=n;i++) fac[i]=((long long)fac[i-1]*i)%tt;
    inv[1]=1;
    for(int i=2;i<=n;i++)inv[i]=tt-(long long)(tt/i)*inv[tt%i]%tt; // 阶乘的逆元
    inv[0]=1;
    for(int i=1;i<=n;i++)inv[i]=(long long)inv[i-1]*inv[i]%tt;
}
inline int C(int x,int y){
    return (long long)fac[x]*inv[y]%tt*inv[x-y]%tt;
}
int main(){
    n=read();Init();
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++){
        a[i]=read();
        if (a[i]!=-1) vis[a[i]]=1;
    }
    for (int i=1;i<=n;i++) if (a[i]==-1){
        if (vis[i]) num_b++; else num_a++;
    }
    f[0]=fac[num_b];
    for (int i=1;i<=num_a;i++){
        f[i]=fac[i+num_b];
        for (int j=1;j<=i;j++) f[i]=(long long)((long long)f[i]-(long long)((long long)C(i,j)*f[i-j])%tt+tt)%tt;
    }
    printf("%d\n",f[num_a]);
    return 0;
}
