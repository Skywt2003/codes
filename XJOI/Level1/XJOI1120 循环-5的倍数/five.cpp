#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a,b,cnt=0;
int main(){
	scanf("%d%d",&a,&b);
	for (int i=a;i<=b;i++){
		int sum=0,x=i;
		while (x) sum+=x%10,x/=10;
		if (sum%5==0) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
