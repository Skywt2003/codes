#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=15,maxs=1024+10,maxw=10005;
const int INF=0x3f3f3f3f3f3f3f3f;

int n,m,a[maxn],s;
int f[maxs],g[maxs],sum[maxs];
int ans1=INF,ans2=INF;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	freopen("zhanshajihua.in","r",stdin);
	freopen("zhanshajihua.out","w",stdout);
	n=read();m=read();s=1<<n;
	for (int i=0;i<n;++i) a[i]=read();
	
	for (int i=0;i<s;i++){
		for (int j=0;j<n;j++) if (i&(1<<j)){
			sum[i]+=(a[j]-1)%3+1;
			f[i]=max((a[j]-1)/3,f[i]);
			int now=(a[j]-1)%3+1;
			if (now<=2) g[i]++; else g[i]+=4;
		}
		if (sum[i]>=m){
			if (f[i]<ans1 || (f[i]==ans1 && f[i]+g[i]<ans2)){
				ans1=f[i];
				ans2=f[i]+g[i];
			}
		}
	}

	if (ans1==INF) printf("-1\n"); else printf("%lld %lld\n",ans1,ans2);
	return 0;
}