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

int T,n,m;
int p[maxn],q[maxn];
int cnt[2];

signed main(){
	T=read();
	while (T--){
		cnt[0]=cnt[1]=0; int ans=0;
		n=read();
		for (int i=1;i<=n;i++) p[i]=read(),cnt[p[i]&1]++;
		m=read();
		for (int i=1;i<=m;i++) q[i]=read(),ans+=cnt[q[i]&1];
		printf("%lld\n",ans);
	}
	return 0;
}