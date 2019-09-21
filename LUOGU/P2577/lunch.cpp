#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=205;
int INF;

int n;
pair<int,int> a[maxn];
int f[maxn][maxn*maxn];
int sum[maxn];

bool compare_second(pair<int,int> aa,pair<int,int> bb){
    return aa.second > bb.second;
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i].first=read(),a[i].second=read();
    sort(a+1,a+1+n,compare_second);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].first;

    memset(f,63,sizeof(f)); INF=f[0][0];
    f[0][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=sum[i];j++){
            if (j>=a[i].first) f[i][j]=min(f[i][j],max(f[i-1][j-a[i].first],j+a[i].second));
            f[i][j]=min(f[i][j],max(f[i-1][j],sum[i]-j+a[i].second));
        }

    int ans=INF;
    for (int i=0;i<=sum[n];i++) ans=min(ans,f[n][i]);
    printf("%d\n",ans);
    return 0;
}