#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=25;

int n;
int a[maxn];
int num1=-1,num2=-1;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();

	for (int i=1;i<=n+1;i++) if (!a[i]) {num1=i-1;break;}
	for (int i=n;i>=0;i--) if (!a[i]) {num2=n-i;break;}

	if ((num1&1) || (num2&1)) printf("YES\n"); else printf("NO\n");
	return 0;
}