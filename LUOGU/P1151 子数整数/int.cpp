#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int k,ans=0;
inline bool check(int x){
	int s1=x/100,s2=(x/10)%1000,s3=x%1000;
	if (s1%k==0&&s2%k==0&&s3%k==0) return true;
	return false;
}
int main(){
	scanf("%d",&k);
	for (int i=10000;i<=30000;i++) if (check(i)) printf("%d\n",i),ans++;
	if (ans==0) printf("No\n");
	return 0;
}
