#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,a=0,b=0;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++){
		int x=read();
		if (x>a) a=x;
	}
	for (int i=1;i<=m;i++){
		int x=read();
		if (x>b) b=x;
	}
	printf("%d\n",a+b);
	return 0;
}
