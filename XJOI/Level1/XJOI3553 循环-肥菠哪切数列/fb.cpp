#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,a[3];
int main(){
	a[1]=a[2]=1;
	scanf("%d",&n);
	for (int i=3;i<=n;i++) a[i%3]=a[(i+2)%3]+a[(i+1)%3];
	printf("%d\n",a[n%3]);
	return 0;
}
