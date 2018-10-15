#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a,b,r;
int main(){
	scanf("%d%d%d",&a,&b,&r);
	if (2*r>a||2*r>b) printf("Bob win\n"); else printf("Alice win\n");
	return 0; 
}
