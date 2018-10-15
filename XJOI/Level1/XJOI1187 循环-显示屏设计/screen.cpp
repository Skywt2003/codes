#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int n,x,y;
int main(){
	scanf("%d",&n);
	x=y=sqrt(n);
	while (x*y!=n){
		if (x*y<n) y++; else
		if (x*y>n) x--;
	}
	printf("%d %d\n",x,y);
	return 0;
}
