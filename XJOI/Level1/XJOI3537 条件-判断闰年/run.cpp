#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
	int x;scanf("%d",&x);
	if (x%1000==0) printf("yes\n"); else
	if (x%100==0) printf("no\n"); else
	if (x%4==0) printf("yes\n"); else printf("no\n");
	return 0;
}
