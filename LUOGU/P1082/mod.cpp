#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a,b;
inline int exgcd(int a,int b,int &x,int &y){
	if (b==0){
		x=1;y=0;return a;
	}
	int ret=exgcd(b,a%b,x,y),t=x;
	x=y;y=t-a/b*y;
	return ret;
}
int main(){
	scanf("%d%d",&a,&b);
	int xs=0,ys=0;
	exgcd(a,b,xs,ys);
	printf("%d\n",(xs+b)%b);
	return 0;
}
