#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	for (int i=1000;i<n;i++){
		int a=i%100,b=i/100;
		if ((a+b)*(a+b)==i) printf("%d\n",i);
	}
	return 0;
}
