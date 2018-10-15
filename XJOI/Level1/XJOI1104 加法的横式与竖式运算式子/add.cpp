#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int x,y,z;
int main(){
	scanf("%d%d",&x,&y);
	z=x+y;
	printf("%d+%d=%d\n",x,y,z);
	printf("%7d\n",x);
	printf("+%6d\n",y);
	printf("-------\n");
	printf("%7d\n",z);
	return 0;
}
