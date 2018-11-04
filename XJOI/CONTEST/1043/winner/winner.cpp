#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int n,m;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();m=read();
	printf("%.6lf\n",1.0*n*(n-1)/2/m);
	return 0;
}