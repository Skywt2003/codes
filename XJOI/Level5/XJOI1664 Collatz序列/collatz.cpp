#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=32005;
int n,ans=1;
int main(){
	scanf("%d",&n);
	for (;;){
		if (n==1) break; else
		if ((n&1)==0) n/=2; else
		if (n&1) n=n*3+1;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
