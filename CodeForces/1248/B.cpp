#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;

int n;
int a[maxn];

int x=0,y=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);

	for (int i=1;i<=n/2;i++) x+=a[i];
	for (int i=n/2+1;i<=n;i++) y+=a[i];
	printf("%lld\n",x*x+y*y);
	return 0;
}