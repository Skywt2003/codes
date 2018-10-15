#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005;
int n,m,f[maxn][maxn];
char a[maxn],b[maxn];
int main(){
    scanf("%s",a+1);n=strlen(a+1);
    scanf("%s",b+1);m=strlen(b+1);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++){
        if (a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
        f[i][j]=max(f[i][j],f[i-1][j]);
        f[i][j]=max(f[i][j],f[i][j-1]);
    }
    printf("%d\n",f[n][m]);
    return 0;
}