#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
const int maxn=100005,maxm=30;
int n,m,a[maxn],f[maxn][maxm];
map <char,int> num;
int main(){
    scanf("%d%d",&n,&m);int cnt=0;
    char ch=getchar();while (ch<'A'||ch>'Z') ch=getchar();
    for (int i=1;i<=n;i++){
        if (num[ch]==0) num[ch]=++cnt;
        a[i]=num[ch];
        ch=getchar();
    }
    memset(f,63,sizeof(f));
    for (int i=1;i<=m;i++) f[0][i]=0;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    for (int k=1;k<=m;k++) if (j-k)
        if (f[i-1][k]+(1-(a[i]==j)) < f[i][j]) f[i][j]=f[i-1][k]+(1-(a[i]==j));
    int ans=1<<30;
    for (int i=1;i<=m;i++) if (f[n][i]<ans) ans=f[n][i];
    printf("%d\n",ans);
    return 0;
}