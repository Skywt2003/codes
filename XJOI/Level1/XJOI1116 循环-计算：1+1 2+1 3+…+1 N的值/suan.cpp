#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n;
double ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) ans+=1.0/i;
	printf("%.6f\n",ans);
	return 0;
}
