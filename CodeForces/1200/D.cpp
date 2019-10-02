#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int read_ch(){
    char ch=getchar();
    while (ch!='B' && ch!='W') ch=getchar();
    return ch=='B';
}

const int maxn=2005;
int n,k,ben=0,ans=0;
int a[maxn][maxn];

int fl[maxn][maxn],suml[maxn][maxn];
int fc[maxn][maxn],sumc[maxn][maxn];

signed main(){
    n=read(); k=read();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j]=read_ch();
    
    for (int i=1;i<=n;i++){
        int tl=-1,tr=-1;
        for (int j=1;j<=n;j++) if (a[i][j]) {tl=j;break;}
        for (int j=n;j>=1;j--) if (a[i][j]) {tr=j;break;}
        if (tl==-1){
            ben++;
            continue;
        }
        if (tr-tl+1 > k) continue;
        for (int j=tl-(k-(tr-tl+1));j<=tl;j++) fl[i][j]=1;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n-k+1;j++)
            suml[i][j]=suml[i-1][j]+fl[i][j];

    for (int j=1;j<=n;j++){
        int tl=-1,tr=-1;
        for (int i=1;i<=n;i++) if (a[i][j]) {tl=i;break;}
        for (int i=n;i>=1;i--) if (a[i][j]) {tr=i;break;}
        if (tl==-1){
            ben++;
            continue;
        }
        if (tr-tl+1 > k) continue;
        for (int i=tl-(k-(tr-tl+1));i<=tl;i++) fc[i][j]=1;
    }
    for (int j=1;j<=n;j++)
        for (int i=1;i<=n-k+1;i++)
            sumc[i][j]=sumc[i][j-1]+fc[i][j];

    for (int i=1;i<=n-k+1;i++)
        for (int j=1;j<=n-k+1;j++){
            ans=max(ans,ben + suml[i+k-1][j]-suml[i-1][j]+sumc[i][j+k-1]-sumc[i][j-1]);
        }
    printf("%d\n",ans);
    return 0;
}