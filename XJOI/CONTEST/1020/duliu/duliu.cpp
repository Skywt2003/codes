#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

#define int long long

const int maxn=200007;
int n,a[maxn],b[maxn];
int ans=0,spc=-1;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

namespace Number{
	map<int,int> num;
	int cnt=0;

	inline int getnum(int x){
		if (num[x]==0){
			num[x]=++cnt;
			return cnt;
		} else return num[x];
	}
}

namespace UniSet{
	int fa[maxn],sum[maxn];

	inline void init(int n){
		for (int i=1;i<=n;i++) fa[i]=i,sum[i]=1;
	}

	inline int getfa(int x){
		if (fa[x]==x) return x;
		fa[x]=getfa(fa[x]);
		return fa[x];
	}

	inline void merge(int x,int y){
		int fx=getfa(x),fy=getfa(y);
		if (fx!=fy) fa[fx]=fy,sum[fy]+=sum[fx],sum[fx]=0;
	}

	bool vis[maxn];

	inline void count(){
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=Number::cnt;i++){
			int f=getfa(i);
			if (vis[f]) continue;
			vis[f]=true;
			if (sum[f]==1 && f!=spc) continue;
			ans++;
		}
		ans--;
	}
}

inline bool check(){
	sort(a+1,a+1+n+1);
	sort(b+1,b+1+n+1);
	for (int i=1;i<=n+1;i++) if (a[i]!=b[i]) return printf("-1\n"),false;
	return true;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),a[n+1]^=a[i];
	for (int i=1;i<=n;i++) b[i]=read(),b[n+1]^=b[i],ans+=a[i]!=b[i];
	spc=Number::getnum(a[n+1]);
	UniSet::init(n+1);
	for (int i=1;i<=n+1;i++) UniSet::merge(Number::getnum(a[i]),Number::getnum(b[i]));
	if (!check()) return 0;
	UniSet::count();
	printf("%lld\n",ans<0?0:ans);
	return 0;
}