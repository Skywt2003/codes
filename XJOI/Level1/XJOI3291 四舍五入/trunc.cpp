#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int x;
double y;
int main(){
	scanf("%d",&x);
	y=(double)x/10.0;
	printf("%d\n",(int)(y+0.5)*10);
	return 0;
}
