#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,cnt=0;
int main(){
	scanf("%d",&n);
	while (n!=1){
		if (n&1) n=n*3+1; else n/=2;
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
