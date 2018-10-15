#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,cnt=0;
int main(){
	scanf("%d",&n);
	for (int i=0;i<=n/5;i++)
	for (int j=0;j<=(n-5*i)/2;j++) cnt++;
	printf("%d\n",cnt);
	return 0;
}
