#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,sum=0;
int main(){
	scanf("%d",&n);
	for (int i=7;i<=n;i++) if (i%7==0) sum+=i;
	printf("%d\n",sum);
	return 0;
}
