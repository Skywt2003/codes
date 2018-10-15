#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	printf("%d\n%d\n",x*y*2+y*z*2+z*x*2,x*y*z);
	return 0;
}
