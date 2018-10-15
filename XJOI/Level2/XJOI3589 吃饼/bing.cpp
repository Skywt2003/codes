#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005,maxw=15,INF=1<<30;
int n,allt=0,f[maxn][maxw],b[maxn][maxw]; //F[i][j]: How many bing he can have in i sec, the last sec he is at j
inline int max3(int x,int y,int z){
    int ret=x;
    if (y>ret) ret=y;
    if (z>ret) ret=z;
    return ret;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int x,t;
        scanf("%d%d",&x,&t);x++;
        b[t][x]++;if (t>allt) allt=t;
    }
    for (int i=0;i<=12;i++) f[0][i]=-INF;
    f[0][6]=0;
    for (int i=1;i<=allt;i++)
    for (int j=1;j<=11;j++){
        f[i][j]=b[i][j]+max3(f[i-1][j],f[i-1][j-1],f[i-1][j+1]);
    }
    int ans=0;
    for (int i=1;i<=11;i++) if (f[allt][i]>ans) ans=f[allt][i];
    printf("%d\n",ans);
    return 0;
}