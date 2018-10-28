#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005;
int n,m;
double f[maxn][maxn];
int main(){
    scanf("%d%d",&n,&m);
    for (int i=n;i>=0;i--)
        for (int j=m;j>=0;j--){
            if (i==n&&j==m) continue;
            f[i][j]+=(f[i  ][j  ]+1.0)*(double)i*j/(n*m-i*j);
            f[i][j]+=(f[i+1][j+1]+1.0)*(double)(n-i)*(m-j)/(n*m-i*j);
            f[i][j]+=(f[i+1][j  ]+1.0)*(double)(n-i)*j/(n*m-i*j);
            f[i][j]+=(f[i  ][j+1]+1.0)*(double)i*(m-j)/(n*m-i*j);
        }
    printf("%.10f\n",f[0][0]);
    return 0;
}
