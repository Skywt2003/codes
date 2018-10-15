#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=205;
int n,top=0,f[maxn][maxn];
char a[maxn];
int main(){
    scanf("%s",a+1);n=strlen(a+1);
    memset(f,63,sizeof(f));
    for (int i=0;i<=n;i++) f[i][i]=1,f[i+1][i]=0;
    for (int L=1;L<=n;L++)
    for (int i=1;i<=n-L;i++){
        int j=i+L;
        if ((a[i]=='('&&a[j]==')')||(a[i]=='['&&a[j]==']')) f[i][j]=min(f[i][j],f[i+1][j-1]);
        for (int k=i;k<j;k++) if (f[i][k]+f[k+1][j]<f[i][j]) f[i][j]=f[i][k]+f[k+1][j];
    }
    printf("%d\n",f[1][n]);
    return 0;
}