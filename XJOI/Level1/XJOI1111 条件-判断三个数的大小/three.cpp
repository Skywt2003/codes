#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
inline int max(int x,int y,int z){
	int ret=x;
	if (y>ret) ret=y;
	if (z>ret) ret=z;
	return ret;
}
inline int min(int x,int y,int z){
	int ret=x;
	if (y<ret) ret=y;
	if (z<ret) ret=z;
	return ret;
}
int main(){
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	printf("The maximum number is : %d\n",max(x,y,z));
	printf("The minimum number is : %d\n",min(x,y,z));
	return 0;
}
