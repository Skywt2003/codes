#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int x,y,z;
int main(){
	scanf("%d%d%d",&x,&y,&z);
	x=x*x;y=y*y;z=z*z;
	if (x+y==z||y+z==x||z+x==y) printf("yes\n"); else printf("no\n");
	return 0; 
}
