#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105;
int n,f[maxn][maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            int now=read();
            f[i][j]=max(f[i-1][j],f[i-1][j-1])+now;
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++) if (f[n][i]>ans) ans=f[n][i];
    printf("%d\n",ans);
    return 0;
}