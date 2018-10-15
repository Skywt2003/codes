#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a,b,c;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	for (int i=0;a*i<=c;i++){
		if ((c-i*a)%b==0) {printf("Yes\n");return 0;}
	}
	printf("No\n");
	return 0;
}
