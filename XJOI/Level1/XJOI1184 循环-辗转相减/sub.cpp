#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int x,y;
int main(){
	scanf("%d%d",&x,&y);
	while (x-y) if (x>y) x-=y; else y-=x;
	printf("%d\n",x);
	return 0;
}
