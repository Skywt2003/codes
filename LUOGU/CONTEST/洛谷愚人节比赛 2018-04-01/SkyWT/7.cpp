#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const string nme="karlheinrichmarx";
int n;
int main(){
	scanf("%d",&n);
	if (n<=16) if (nme[n-1]!=' '){
		putchar(nme[n-1]);printf("\n");
	}
	return 0;
}
