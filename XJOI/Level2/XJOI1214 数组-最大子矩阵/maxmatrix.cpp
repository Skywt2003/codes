#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=205;
int n,m,a[maxn][maxn],b[maxn],sum[maxn],ans=0;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++) a[i][j]=read();
    for (int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        for (int j=i;j<=n;j++){
            for (int k=1;k<=m;k++) b[k]+=a[j][k],sum[k]=sum[k-1]+b[k];
            int lst_min=0;
            for (int k=1;k<=m;k++){
                if (sum[k]-lst_min>ans) ans=sum[k]-lst_min;
                if (sum[k]<lst_min) lst_min=sum[k];
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}