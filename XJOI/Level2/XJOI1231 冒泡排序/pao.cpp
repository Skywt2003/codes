#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005;
int n,a[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++){
		for (int j=1;j<n;j++) if (a[j]>a[j+1]) swap(a[j],a[j+1]);
	}
	for (int i=1;i<n;i++) printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}
