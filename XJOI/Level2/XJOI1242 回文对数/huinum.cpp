#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=2005;
int n,lnk[maxn][maxn],sum[maxn];
long long ans=0;
bool vis[maxn][maxn];
char a[maxn];
int main(){
    scanf("%s",a+1);
    n=strlen(a+1);
    for (int i=0;i<=n;i++){
        if (i) lnk[i][++lnk[i][0]]=i;
        vis[i][i]=vis[i+1][i]=1;
    }
    for (int L=1;L<n;L++)
    for (int i=1;i<=n-L+1;i++){
        int j=i+L;
        if (!vis[i+1][j-1]) continue;
        if (a[i]==a[j]){
            vis[i][j]=1;
            lnk[i][++lnk[i][0]]=j;
        }
    }
    for (int i=n;i>=1;i--) sum[i]=sum[i+1]+lnk[i][0];
    for (int i=1;i<=n;i++)
    for (int j=1;j<=lnk[i][0];j++) ans+=(long long)sum[lnk[i][j]+1];
    printf("%lld\n",ans);
    // for (int i=1;i<n;i++)
    // for (int j=i+1;j<=n;j++) printf("[%d,%d]:%d\n",i,j,vis[i][j]);
    return 0;
}