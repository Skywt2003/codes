#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int C2(int x){
    return x*(x-1)/2;
}

const int maxn=105,tt=9999973;
int n,m;
int f[maxn][maxn][maxn];

void add(int &x,int y){
    x=(x+y)%tt;
}

signed main(){
    n=read();m=read();
    f[0][0][0]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=m;j++){
            for (int k=0;k<=m-j;k++){
                f[i][j][k]+=f[i-1][j][k];
                if (k-1>=0) add(f[i][j][k],f[i-1][j+1][k-1]*(j+1));
                if (j-1>=0) add(f[i][j][k],f[i-1][j-1][k  ]*(m-(j-1)-k));
                if (k-1>=0) add(f[i][j][k],f[i-1][j  ][k-1]*j*(m-j-(k-1)));
                if (j-2>=0) add(f[i][j][k],f[i-1][j-2][k  ]*C2(m-(j-2)-k));
                if (k-2>=0) add(f[i][j][k],f[i-1][j+2][k-2]*C2(j+2));
            }
        }
    }
    int ans=0;
    for (int i=0;i<=m;i++)
    for (int j=0;j<=m;j++)
        add(ans,f[n][i][j]);
    printf("%lld\n",ans);
    return 0;
}