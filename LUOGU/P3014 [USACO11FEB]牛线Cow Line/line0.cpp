#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=25;
int n,m,a[maxn],b[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline char read_ch(){
	char ch=getchar();
	while (ch!='Q'&&ch!='P') ch=getchar();
	return ch;
}
inline void change(){
	int fd=-1;
	for (int i=n-1;i>=1;i--) if (a[i]<a[i+1]) {fd=i;break;}
	int th=-1,sub=1<<30;
	for (int i=fd+1;i<=n;i++) if (a[i]>a[fd]&&a[i]-a[fd]<sub) sub=a[i]-a[fd],th=i;
	swap(a[fd],a[th]);
	sort(a+fd+1,a+n+1);
	for (int i=1;i<n;i++) printf("%d ",a[i]);
	printf("%d\n",a[n]);
}
int main(){
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	n=read();m=read();
	for (int k=1;k<=m;k++){
		for (int i=1;i<=n;i++) a[i]=i;
		char now=read_ch();
		if (now=='P'){
			int x=read();
			for (int i=1;i<x;i++) change();
			for (int i=1;i<n;i++) printf("%d ",a[i]);
			printf("%d\n",a[n]);
		} else if (now=='Q'){
			int cnt=1;
			for (int i=1;i<=n;i++) b[i]=read();
			while (1){
				bool dft=false;
				for (int i=1;i<=n;i++) if (a[i]!=b[i]){dft=true;break;}
				if (!dft) break;
				change();cnt++;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}
