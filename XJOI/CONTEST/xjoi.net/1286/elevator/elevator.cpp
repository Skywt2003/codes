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

int n,k,ans=0;
int a[maxn];

signed main(){
	n=read(); k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);

	int j=n;
	for (int i=1;i<=j;){
		if (i==j) ans++,i++; else 
		if (a[i]+a[j] <= k) ans++,i+=2; else
		i++,j--,ans+=2;
	}

	printf("%lld\n",ans);
	return 0;
}