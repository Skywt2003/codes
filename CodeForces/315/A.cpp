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
int n;
int a[maxn],b[maxn];
int sum[1005];

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read(),sum[b[i]]++;
	int ans=0;
	for (int i=1;i<=n;i++){
		if (sum[a[i]]==0 || (sum[a[i]]==1 && b[i]==a[i])) ans++;
	}
	printf("%lld\n",ans);
	return 0;
}