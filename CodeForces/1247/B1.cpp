#include<bits/stdc++.h>
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
const int maxn=105;

int T;
int n,k,d;

int a[maxn];
int vis[maxn];

signed main(){
	T=read();
	while (T--){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		int ans=INF;

		n=read(); k=read(); d=read();
		for (int i=1;i<=n;i++) a[i]=read();

		for (int i=1;i<=d;i++) vis[a[i]]++;
		for (int i=d;i<=n;i++){
			int now=0;
			for (int j=1;j<=k;j++) if (vis[j]) now++;
			ans=min(ans,now);

			vis[a[i-d+1]]--;
			vis[a[i+1]]++;
		}

		printf("%lld\n",ans);
	}
	return 0;
}