#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n;
int main(){
	while (scanf("%d",&n)!=-1){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n-i;j++) putchar(' ');
			for (int j=1;j<=2*i-1;j++) putchar('*');
			printf("\n");
		}
	}
	return 0;
}
