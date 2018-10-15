#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
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
	sort(a+1,a+1+n);
	int i=1,j;
	while (i<=n){
		j=i;
		while (a[j+1]==a[i]) j++;
		if (j-i+1>n/2){
			printf("%d\n",a[i]);
			return 0;
		}
		i=j+1;
	}
	return 0;
}
