#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105;
int n,m,a[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		for (int j=x;j<=y;j++) a[j]+=z;
	}
	for (int i=1;i<n;i++) printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}
