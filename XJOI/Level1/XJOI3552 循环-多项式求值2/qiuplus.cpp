#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,ans=0;
int main(){
	scanf("%d",&n);
	int now=0;
	for (int i=1;i<=n;i++) now+=i,ans+=now;
	printf("%d\n",ans);
	return 0;
}
