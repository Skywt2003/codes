#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10005;
int n,m,a[maxn],b[maxn],f[maxn][maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();m=read();
	for (int i=1;i<n;i++) a[i]=read();
	for (int i=1;i<m;i++) b[i]=read();
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++){
		if (i==0&&j==0) continue; else
		if (i==0) f[i][j]=f[i][j-1]+b[j]; else
		if (j==0) f[i][j]=f[i-1][j]+a[i]; else
		if (f[i-1][j]+(j+1)*a[i] < f[i][j-1]+(i+1)*b[j]) f[i][j]=f[i-1][j]+(j+1)*a[i]; else f[i][j]=f[i][j-1]+(i+1)*b[j];
	}
	printf("%d\n",f[n-1][m-1]);
	printf("------------------\n");
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++) printf("%d ",f[i][j]);
		printf("\n");
	}
	return 0;
}
