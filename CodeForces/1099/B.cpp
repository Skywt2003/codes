#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;

signed main(){
	n=read();
	int a=1,b=1;
	for (int i=1;i<=n;i++){
		if (a*b>=n){
			printf("%lld\n",a+b);
			return 0;
		}
		if (a<b) a++; else b++;
	}
	printf("%lld\n",n+1);
	return 0;
}