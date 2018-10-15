#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
	int x;
	scanf("%d",&x);
	if (x&1) printf("odd\n"); else printf("even\n");
	return 0;
}
