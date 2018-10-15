#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    if (n==k||k==0) printf("0 "); else printf("1 ");
    printf("%d\n",min(2*k,n-k));
}