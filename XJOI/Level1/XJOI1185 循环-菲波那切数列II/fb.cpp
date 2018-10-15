#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n;
long long a[3];
int main(){
	scanf("%d",&n);
	a[1]=0;a[2]=1;
	for (int i=3;i<=n;i++) a[i%3]=(long long)a[(i+1)%3]+a[(i+2)%3];
	printf("%lld\n",a[n%3]);
	return 0;
}
