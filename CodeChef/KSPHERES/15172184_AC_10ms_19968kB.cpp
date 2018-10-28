#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005,maxq=1005,tt=1000000007;
int n,m,q,a[maxn],b[maxn],cnt1[maxq],cnt2[maxq],f[maxq][maxq];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    n=read();m=read();q=read();q++;
    for (int i=1;i<=n;i++) a[i]=read(),cnt1[a[i]]++;
    for (int i=1;i<=m;i++) b[i]=read(),cnt2[b[i]]++;
    for (int i=0;i<=q;i++) f[i][0]=1;
    //f[0][0]=1;
    for (int i=1;i<=q;i++)
    for (int j=1;j<=q;j++){
        f[i][j]=((long long)f[i-1][j-1]*cnt1[i]*cnt2[i]+f[i-1][j])%tt;
        //printf("F[%d][%d]= %d\n",i,j,f[i][j]);
    }
    for (int i=2;i<=q;i++) printf("%d ",f[q][i]);
    printf("\n");
    return 0;
}