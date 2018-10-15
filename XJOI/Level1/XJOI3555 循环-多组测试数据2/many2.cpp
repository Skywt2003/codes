#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,x,y;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",x+y);
	}
	return 0;
}
