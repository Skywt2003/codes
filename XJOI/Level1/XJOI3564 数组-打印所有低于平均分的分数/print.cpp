#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105;
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
		int sum=0;
		for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
		sum=(sum+n-1)/n;
		bool flg=false;
		for (int i=1;i<=n;i++) if (a[i]<sum){if (flg==false) {printf("%d",a[i]);flg=1;} else printf(" %d",a[i]);}
		printf("\n");
	}
	return 0;
}
