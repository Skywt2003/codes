#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	double xx=log2(n)/log2(5);
	int yy=(int)(log2(n)/log2(5));
	if ((double)xx-(double)yy<=1e-8){
		printf("impossible\n");
		return 0;
	}
	printf("%d\n",n*5);
	return 0;
}
