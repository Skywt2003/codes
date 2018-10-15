#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,a;
int main(){
	scanf("%d%d%d",&n,&m,&a);
	printf("%d\n",((n+a-1)/a)*((m+a-1)/a));
	return 0;
}
