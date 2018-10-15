#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if (n>60) printf("NO\n"); else
	if (n<=30) printf("%.2f\n",0.2*n); else
	printf("%.2f\n",6.0+0.6*(n-30));
	return 0;
}
