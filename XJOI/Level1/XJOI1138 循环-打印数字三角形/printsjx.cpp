#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,x=0;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++) printf("%4d",++x);
		printf("\n");
	}
	return 0;
}
