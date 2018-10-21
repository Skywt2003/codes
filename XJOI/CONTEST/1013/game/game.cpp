/*
 * XJOI CONTEST 1013
 * T1 - game
 * 181005 By SkyWT
 */
 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
 
using namespace std;
 
#define int long long
 
#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))
 
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
 
const int maxn=2005;
int n,m,q,ans=(int)1e18;
int a[maxn][maxn],sum[maxn],tmp[maxn];
 
inline bool bigcmp(int x,int y){return x>y;}
 
signed main(){
    n=read();m=read();q=read();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j]=read();
            tmp[i]+=a[i][j];
        }
        sort(a[i]+1,a[i]+1+m,bigcmp);
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++) sum[i]=tmp[i];
        int now=0;
        for (int i=1;i<=q%m;i++) now+=a[k][i];
        if (q%m) sum[k]=1e18+100;
        sort(sum+1,sum+1+n);
        for (int i=1;i<=q/m;i++) now+=sum[i];
        ans=min(ans,now);
    }
    printf("%lld\n",ans);
    return 0;
}