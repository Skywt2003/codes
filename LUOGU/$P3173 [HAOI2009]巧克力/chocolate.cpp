#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10005;
int n,m,a[maxn],b[maxn],sum_a[maxn],sum_b[maxn],ans=0;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();m=read();
	for (int i=1;i<n;i++) a[i]=read();
	for (int i=n-1;i>=1;i--) sum_a[i]=sum_a[i+1]+a[i];
	for (int i=1;i<m;i++) b[i]=read();
	for (int i=m-1;i>=1;i--) sum_b[i]=sum_b[i+1]+b[i];
	int i=1,j=1;
	while (i<n||j<m){
		if (i<n&&(a[i]*j+sum_b[j]<b[j]*i+sum_a[i])) {ans+=a[i]*j;i++;}
		else {ans+=b[j]*i;j++;}
	}
	printf("%d\n",ans);
	return 0;
}
