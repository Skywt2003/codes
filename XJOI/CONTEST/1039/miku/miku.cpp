#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1505;
int n,m,L,R;
int a[maxn];

signed main(){
	n=read();m=read();L=read();R=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++){
		int l=read(),r=read();
		sort(a+l,a+r+1);
	}
	for (int i=L;i<=R;i++) printf("%lld ",a[i]);
	printf("\n");
	return 0;
}