#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int a,b,c;

int main(){
	a=read();b=read();c=read();
	a+=2;b++;
	printf("%d\n",min(a,min(b,c))*3-3);
	return 0;
}