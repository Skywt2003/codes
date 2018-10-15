#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int sum=0;
	for (int i=1;i<=n;i++) sum+=i;
	printf("%d\n",sum);
	return 0;
}
