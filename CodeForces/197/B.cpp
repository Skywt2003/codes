#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105;
int n,m;
int a[maxn],b[maxn];

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

inline int myabs(int x){
	return x<0?-x:x;
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=n+1;i++) a[i]=read();
	for (int i=1;i<=m+1;i++) b[i]=read();
	if (n>m){
		if ((a[1]<0 && b[1]>0)||(a[1]>0 && b[1]<0)) putchar('-');
		printf("Infinity\n");
		return 0;
	} else if (n<m){
		printf("0/1\n");
		return 0;
	} else {
		if (b[1]<0 && a[1]>0) a[1]=-a[1],b[1]=-b[1]; else
		if (b[1]<0 && a[1]<0) a[1]=-a[1],b[1]=-b[1];
		int g=gcd(myabs(a[1]),myabs(b[1]));
		printf("%lld/%lld\n",a[1]/g,b[1]/g);
		return 0;
	}
	return 0;
}