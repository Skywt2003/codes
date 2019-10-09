#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=2005;

int n,m;
bool a[maxn][maxn];
int ans1=0,ans2=0;

int lft[maxn][maxn],rght[maxn][maxn],up[maxn][maxn];

signed main(){
    n=read(); m=read();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            a[i][j]=read();
    
    for (int i=1;i<=n;i++){
        lft[i][1]=1;
        for (int j=2;j<=m;j++)
            lft[i][j]=(a[i][j]^a[i][j-1])?lft[i][j-1]:j;
        rght[i][m]=m;
        for (int j=m-1;j>=1;j--)
            rght[i][j]=(a[i][j]^a[i][j+1])?rght[i][j+1]:j;
    }
    
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (i>1 && a[i][j]!=a[i-1][j]){
                up[i][j]=up[i-1][j]+1;
                lft[i][j]=max(lft[i][j],lft[i-1][j]);
            } else up[i][j]=1;
        }
        for (int j=m;j>=1;j--){
            if (i>1 && a[i][j]!=a[i-1][j]){
                rght[i][j]=min(rght[i][j],rght[i-1][j]);
                int w=rght[i][j]-lft[i][j]+1;
                int b=min(up[i][j],w);
                ans1=max(ans1,b*b);
                ans2=max(ans2,up[i][j]*w);
            } else up[i][j]=1;
        }
    }
    printf("%lld\n%lld\n",ans1,ans2);
    return 0;
}