#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,sum=0;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) if (n%i==0) sum+=i;
	printf("%d\n",sum);
	return 0;
}
