#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char ch;
int n;
int main(){
	char ch=getchar();while (ch<'A'||ch>'Z') ch=getchar();
	n=ch-'A'+1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n-i;j++) printf(" ");
		for (int j=0;j<i;j++) putchar('A'+j);
		for (int j=i-2;j>=0;j--) putchar('A'+j);
		printf("\n");
	}
	return 0;
}
