#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
	int x;
	scanf("%d",&x);
	if ((x&1)||(x<4)) printf("NO, you can't divide the watermelon into two even parts.\n"); else
	printf("YES, you can divide the watermelon into two even parts.");
	return 0;
}
