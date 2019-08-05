#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=(int)1<<60;
const int maxn=35;

int n,g[maxn][maxn];

signed main(){
    n=read();
    while (n){
        fill(g[0],g[0]+maxn*maxn,0);
        for (int i=1;i<n;i++)
            for (int j=i+1;j<=n;j++)
                g[i][j]=g[j][i]=read();
        int ans=g[1][2];
        for (int k=3;k<=n;k++){
            int now=INF;
            for (int i=1;i<k-1;i++)
                for (int j=i+1;j<k;j++){
                    now=min(now,(g[i][k]+g[j][k]-g[i][j])/2);
                }
            ans+=now;
        }
        printf("%lld\n",ans);
        n=read();
    }
    return 0;
}