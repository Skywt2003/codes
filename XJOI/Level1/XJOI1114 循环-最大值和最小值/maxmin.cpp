#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,maxx=-(1<<30),minx=1<<30;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x=read();
		if (x>maxx) maxx=x;
		if (x<minx) minx=x;
	}
	printf("%d\n%d\n",maxx,minx);
	return 0;
}
