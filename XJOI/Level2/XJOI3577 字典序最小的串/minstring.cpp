#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=2005;
int n,L,R;
char a[maxn];
int main(){
    scanf("%d",&n);
    scanf("%s",a);
    L=0,R=n-1;
    for (int k=1;k<=n;k++){
        int i=L,j=R;
        while (a[i]==a[j]&&i<j) i++,j--;
        if (a[i]>a[j]) {putchar(a[R]);R--;} else {putchar(a[L]);L++;}
    }
    printf("\n");
    return 0;
}