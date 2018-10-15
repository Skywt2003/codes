#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,a[3];
int main(){
	scanf("%d",&n);
	a[1]=0,a[2]=1;
	for (int i=1;i<=n;i++){
		if (i!=1&&i!=2) a[i%3]=a[(i+2)%3]+a[(i+1)%3];
		if (i==n) printf("%d\n",a[i%3]); else printf("%d ",a[i%3]);
	}
	return 0;
}
