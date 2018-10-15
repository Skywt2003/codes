#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,x,ans=0;
int main(){
	scanf("%d",&n);
	x=1;
	for (int i=1;i<=n;i++) x*=i,ans+=x;
	printf("%d\n",ans);
	return 0;
}
