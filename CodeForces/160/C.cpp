#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;
int n,k;
int a[maxn];

signed main(){
	n=read();k=read();
	a[0]=a[n+1]=1e9+123;
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	if (a[(k-1)/n+1]==a[(k-1)/n] || a[(k-1)/n+1]==a[(k-1)/n+2]){
		int cnt=1,l=(k-1)/n+1,r=(k-1)/n+1;
		while (a[l-1]==a[l]) l--,cnt++;
		while (a[r+1]==a[r]) r++,cnt++;
		int num=((k-1)/n+1 - l)*n + (k-1)%n+1;
		num=(num+cnt-1)/cnt;
		printf("%lld %lld\n",a[(k-1)/n+1],a[num]);
		return 0;
	}
	printf("%lld %lld\n",a[(k-1)/n+1],a[(k-1)%n+1]);
	return 0;
}