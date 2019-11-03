#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=506;

int n;
int a[maxn][maxn];
int ans=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			a[i][j]=a[j][i]=read();
	for (int i=1;i<=n;i++){
		sort(a[i]+1,a[i]+1+n);
		ans=max(ans,a[i][n-1]);
	}
	printf("1\n%lld\n",ans);
	return 0;
}