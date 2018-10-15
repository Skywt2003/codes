#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,a[10];
inline bool check(int x){
	memset(a,0,sizeof(a));
	while (x) a[++a[0]]=x%10,x/=10;
	int i=1,j=a[0];
	while (i<j){
		if (a[i]-a[j]) return false;
		i++;j--;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) if (check(i)) printf("%d\n",i);
	return 0;
}
