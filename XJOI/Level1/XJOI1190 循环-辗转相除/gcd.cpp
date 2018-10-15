#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a,b;
inline int gcd(int x,int y){
	if (y==0) return x;
	return gcd(y,x%y);
}
int main(){
	scanf("%d%d",&a,&b);
	printf("%d\n",gcd(a,b));
	return 0;
}
