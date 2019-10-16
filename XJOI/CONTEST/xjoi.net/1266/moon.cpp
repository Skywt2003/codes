#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1000005;

int n,m,w[maxn],t[maxn];

namespace subtask3{
	int sum[maxn];

	signed main(){
		for (int i=1;i<=m;i++) sum[i]=sum[i-1]+w[i];

		#define mid (((R-L)>>1)+L)
		for (int i=1;i<=n;i++){
			int L=1,R=n,ans=0;
			while (L<=R){
				if (sum[mid] <= t[i]) ans=mid,L=mid+1; else R=mid-1;
			}
			printf("%lld\n",ans);
		}
		#undef mid
		return 0;
	}
}

signed main(){
	m=read(); n=read();
	for (int i=1;i<=m;i++) w[i]=read();
	for (int i=1;i<=n;i++) t[i]=read();

	if (n>5000 || m>5000) return subtask3::main();

	for (int i=1;i<=n;i++){
		int ans=0;
		for (int j=1;j<=m && t[i]>0;j++)
			if (w[j]<=t[i]) t[i]-=w[j],ans++;
		printf("%lld\n",ans);
	}
	return 0;
}