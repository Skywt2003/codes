#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n;
double x=100.0;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) x=x*1.08;
	printf("%.2f\n",x);
	return 0;
}
