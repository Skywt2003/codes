#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n;
double ans=0.0;
int main(){
	scanf("%d",&n);
	int mum=1;
	for (int i=1;i<=n;i++){
		ans+=1.0/mum;
		if (i&1) mum-=2*i+1; else mum+=2*i+1;
	}
	printf("%.3f\n",ans);
	return 0;
}
