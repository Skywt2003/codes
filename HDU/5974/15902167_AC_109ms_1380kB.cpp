#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int x,y,a,b;
inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	while (~scanf("%d%d",&a,&b)){
		int g=gcd(a,b);
		x=(a+sqrt(a*a-4*b*g))/2;
		y=a-x;
		if (x>y) swap(x,y);
		if ((x<0)||(y<0)||(x+y!=a)||((x/gcd(x,y)*y)!=b)) printf("No Solution\n"); else printf("%d %d\n",x,y);
	}
	return 0;
}