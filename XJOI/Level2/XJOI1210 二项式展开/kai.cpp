#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=50;
int n,a[maxn][maxn];
int main(){
    scanf("%d",&n);
    if (n==0){printf("(a+b)^0 = 1\n");return 0;}
    a[1][1]=a[1][2]=1;
    for (int i=2;i<=n;i++){
        a[i][1]=1;
        for (int j=2;j<=i;j++) a[i][j]=a[i-1][j]+a[i-1][j-1];
        a[i][i+1]=1;
    }
    printf("(a+b)^%d =",n);
    int xa=n,xb=0;
    for (int i=1;i<=n+1;i++){
        printf(" ");
        if (a[n][i]>1) printf("%d",a[n][i]);

        if (xa!=0&&a[n][i]!=1) printf("*"); 
        if (xa==1) printf("a"); else
        if (xa>1) printf("a^%d",xa);

        if (xb!=0&&((xa==0&&a[n][i]!=1)||(xa!=0))) printf("*"); 
        if (xb==1) printf("b"); else
        if (xb>1) printf("b^%d",xb);

        xa--;xb++;
        if (i!=n+1) printf(" +");
    }
    printf("\n");
    return 0;
}