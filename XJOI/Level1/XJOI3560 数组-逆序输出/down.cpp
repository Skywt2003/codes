#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105;
int t,n,a[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	t=read();
	for (int i=1;i<=t;i++){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=n;i>=2;i--) printf("%d ",a[i]);
		printf("%d\n",a[1]);
	}
	return 0;
}
