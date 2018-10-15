#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005;
int n,a[maxn],b[maxn];
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
		int x=1;
		if (i==1||a[i]<b[1]) x=1; else
		if (a[i]>b[i-1]) x=i; else
		for (int j=2;j<i;j++) if (b[j-1]<a[i]&&b[j]>=a[i]){x=j;break;}
		for (int j=i;j>x;j--) b[j]=b[j-1];
		b[x]=a[i];
	}
	for (int i=1;i<n;i++) printf("%d ",b[i]);
	printf("%d\n",b[n]);
	return 0;
}
