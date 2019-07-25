#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=506;
const int g[10]={1,2,4,8,16,32,64,128,256,512};
const int p[10]={2,4,8,16,32,64,128,256,512,1024};
int n;
double f[maxn][maxn];
double ans=0;

signed main(){
    memset(f,0,sizeof(f));
    n=read();
    for (int i=0;i<=n;i++) f[n][i]=1.0;
    for (int i=n-1;i>=0;i--){
        for (int j=n-1;j>=0;j--){
            for (int t=0;t<10;t++){
                int ip=min(i+g[t],n);
                f[i][j]=max(f[i][j],(f[ip][j+1]/p[t]/2 + f[ip][j]/p[t]/2 + f[i][j+1]*(1.0-1.0/p[t])/2) / ((1.0+1.0/p[t])*0.5));
            }
        }
    }
    printf("%.6lf\n",f[0][0]);
    return 0;
}