#include<bits/stdc++.h>

#define int long long

using namespace std;

const int tt1=19260817,tt2=998244353;
const int maxn=105;

int n,m;
pair<int,int> a[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline pair<int,int> read_mod(){
	pair<int,int> ret=make_pair(0ll,0ll); int f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')
		ret.first=(ret.first*10%tt1 +ch-'0')%tt1,
		ret.second=(ret.second*10%tt2 +ch-'0')%tt2,
		ch=getchar();
	ret.first*=f; ret.second*=f;
	return ret;
}

bool check(int x){
	pair<int,int> now=a[n];
	for (int i=n-1;i>=0;i--){
		now.first  = (now.first*x%tt1 + a[i].first)%tt1;
		now.second = (now.second*x%tt2 + a[i].second)%tt2;
	}
	return (now.first==0) && (now.second==0);
}

vector<int> ans;

signed main(){
	n=read(); m=read();
	for (int i=0;i<=n;i++) a[i]=read_mod();

	// for (int i=0;i<=n;i++) printf("%lld %lld\n",a[i].first,a[i].second);

	ans.clear();
	for (int x=1;x<=m;x++) if (check(x)) ans.push_back(x);
	printf("%lld\n",(int)ans.size());
	for (int i=0;i<ans.size();i++) printf("%lld\n",ans[i]);
	return 0;
}