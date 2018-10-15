#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
	int n,sum=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) if (i&1) sum+=i; else sum-=i;
	printf("%d\n",sum);
	return 0;
}
