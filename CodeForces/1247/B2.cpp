#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1e6+5;

int T;
int n,k,d;

int a[maxn];
int vis[maxn];

signed main(){
	T=read();
	while (T--){
		int ans=INF;

		n=read(); k=read(); d=read();
		for (int i=1;i<=n;i++) a[i]=read();

		int now=0;
		for (int i=1;i<=d;i++){
			vis[a[i]]++;
			if (vis[a[i]]==1) now++;
		}
		for (int i=d;i<=n;i++){
			ans=min(ans,now);
			if (i==n) continue;

			vis[a[i-d+1]]--;
			if (vis[a[i-d+1]]==0) now--;
			vis[a[i+1]]++;
			if (vis[a[i+1]]==1) now++;
		}
		for (int i=n-d+1;i<=n;i++) vis[a[i]]--;

		printf("%lld\n",ans);
	}
	return 0;
}