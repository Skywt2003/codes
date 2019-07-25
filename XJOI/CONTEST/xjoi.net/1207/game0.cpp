#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=506;
const int c[10]={1,2,4,8,16,32,64,128,256,512};
const int p[10]={2,4,8,16,32,64,128,256,512,1024};
int n;
double f[2][maxn][maxn];
double ans=0;

#define ls (1-(i&1))
#define ns (i&1)

signed main(){
    memset(f,0,sizeof(f));
    n=read();
    f[0][0][0]=1.0;
    for (int i=1;i<=2*n+100;i++){
        memset(f[ns],0,sizeof(f[ns]));
        for (int j=0;j<=n;j++)
        for (int k=0;k<=n;k++){
            int mon=0;
            for (int t=0;t<10;t++) if (t==0 || c[t-1]<n){
                double now=0.0;
                if ((i!=1 || f[ls][j][k]!=0.0) && j!=n && k!=n) now+=f[ls][j][k]*(1.0-1.0/p[t])*0.5;
                if (j>=c[t] && k!=n) now+=f[ls][j-c[t]][k  ]*(1.0/p[t])*0.5;
                if (k>=   1 && j!=n) now+=f[ls][j     ][k-1]*(1.0-1.0/p[t])*0.5;
                if (j>=c[t] && k>=1) now+=f[ls][j-c[t]][k-1]*(1.0/p[t])*0.5;
                f[ns][j][k]+=now;mon++;
            }
            f[ns][j][k]/=mon;
            // printf("f[%d][%d][%d] = %.10lf\n",i,j,k,f[ns][j][k]);
        }
        for (int j=0;j<=n;j++) ans+=f[ns][n][j];
    }
    printf("%.6lf\n",ans);
    return 0;
}