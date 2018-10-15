#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
	int x;
	scanf("%d",&x);
	if ((!(x&1))&&(x>50)) printf("yes\n"); else printf("no\n");
	return 0;
}
