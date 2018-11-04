#include<cstdio>
#include<cstring>
#include<iostream>
#define int long long
using namespace std;

int n,m;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

char s[105];

signed main(){
	n=read();m=read();n=n*(n-1)/2;
	printf("%lld",n/m);n%=m;
	sprintf(s,"%.6lf",(double)n/m);
	printf("%s",s+1);
	return 0;
}