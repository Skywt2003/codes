#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	if (y>x) swap(x,y);
	printf("%d\n%d\n",x,y);
	return 0;
}
