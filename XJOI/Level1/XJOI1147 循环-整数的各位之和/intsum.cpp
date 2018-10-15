#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,sum=0;
int main(){
	scanf("%d",&n);
	while (n) sum+=n%10,n/=10;
	printf("%d\n",sum);
	return 0;
}
