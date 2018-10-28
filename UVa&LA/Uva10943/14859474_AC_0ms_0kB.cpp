#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=205,tt=1000000;
int n,m,f[maxn][maxn]; // Answer: C_{n+m-1}^{m-1}
int main(){
    f[0][0]=1;
    for (int i=1;i<=200;i++){
        f[i][0]=1;
        for (int j=1;j<i;j++) f[i][j]=(f[i-1][j]+f[i-1][j-1])%tt;
        f[i][i]=1;
    }
    scanf("%d%d",&n,&m);
    while (n!=0||m!=0){
        printf("%d\n",f[n+m-1][m-1]);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
