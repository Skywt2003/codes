#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,a[25];
int main(){
	scanf("%d",&n);
	a[1]=0;a[2]=a[3]=1;
	for (int i=4;i<=n;i++) a[i]=a[i-3]+2*a[i-2]+a[i-1];
	printf("%d\n",a[n]);
	return 0;
}
