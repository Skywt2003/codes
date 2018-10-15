#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a,b,c,d;
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d\n",c*60+d-a*60-b);
	return 0;
}
