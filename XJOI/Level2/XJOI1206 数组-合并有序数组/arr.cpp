#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=5000005;
int n,m,a[maxn],b[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) b[i]=read();
	int x=0,y=0;
	for (int i=1;i<=n+m;i++){
		if (x+1<=n&&(a[x+1]<b[y+1]||y+1>m)) {x++;printf("%d ",a[x]);} else {y++;printf("%d ",b[y]);}
	}
	printf("\n");
	return 0;
}
