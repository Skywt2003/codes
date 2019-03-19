#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int w,h,a,b,c,d;
int ans=0;

int main(){
	w=read();h=read();
	a=read();b=read();
	c=read();d=read();
	ans=w;
	for (int i=h;i>=1;i--){
		ans+=i;
		if (i==b) ans-=a;
		if (i==d) ans-=c;
		if (ans<0) ans=0;
	}
	printf("%d\n",ans);
	return 0;
}