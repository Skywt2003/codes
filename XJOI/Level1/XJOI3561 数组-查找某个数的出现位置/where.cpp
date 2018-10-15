#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=25;
int n,a[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	while (1){
		if (scanf("%d",&n)==-1) break;
		for (int i=1;i<=n;i++) a[i]=read();
		int m=read();bool flg=false;
		for (int i=1;i<=n;i++) if (a[i]==m) {printf("%d\n",i-1);flg=1;break;}
		if (flg==false) printf("No\n");
	}
	return 0;
}
