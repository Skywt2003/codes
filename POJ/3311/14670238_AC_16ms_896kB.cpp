#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=15,maxx=5000;
int n,s,dst[maxn][maxn],f[maxx][maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void Floyd(){
    for (int k=0;k<=n;k++)
    for (int i=0;i<=n;i++) if (k!=i)
    for (int j=0;j<=n;j++) if (k!=j&&i!=j)
        dst[i][j]=min(dst[i][j],dst[i][k]+dst[k][j]);
    for (int i=0;i<=n;i++) dst[0][0]=0;
}
inline void PrintNum(int x){
    while (x) printf("%d",x&1),x>>=1;
}
int main(){
    n=read();
    while (n!=0){
        s=1<<(n+1);
        memset(dst,63,sizeof(dst));
        for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++) dst[i][j]=read();
        Floyd();
        memset(f,63,sizeof(f));
        f[1][0]=0;
        for (int j=2;j<s;j++)
        for (int i=0;i<=n;i++) if (j&(1<<i)){
            int lst_dyn=j-(1<<i);
            for (int k=0;k<=n;k++) if (lst_dyn&(1<<k)) f[j][i]=min(f[j][i],f[lst_dyn][k]+dst[k][i]);
        }
        int ans=1<<30;
        for (int i=0;i<=n;i++) if (f[s-1][i]+dst[i][0]<ans) ans=f[s-1][i]+dst[i][0];
        printf("%d\n",ans);
        n=read();
    }
    return 0;
}