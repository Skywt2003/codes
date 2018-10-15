#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,x=0,y=0,z=0;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int a=read();
		if (a>0) x++; else
		if (a==0) y++; else
		if (a<0) z++;
	}
	printf("%d\n%d\n%d\n",x,y,z);
	return 0;
}
