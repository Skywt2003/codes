#include<bits/stdc++.h>

#define int long long

#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e6+5;

int n,m;
int x[maxn];

pii a[maxn];
int num[maxn];
int cnt=0;

const int tt=998244353;

signed main(){
	n=read();m=read();
	for (int i=1;i<=m;i++) x[i]=read();

	sort(x+1,x+1+m);

	for (int i=1;i<=m;i++){
		if (cnt && x[i]==x[i-1]) num[cnt]++; else
		if (cnt && x[i]<=a[cnt].se){
			a[cnt].se++; a[cnt].fi--;
//			if (a[cnt].fi <= mid(a[cnt-1])){
//				a[cnt-1].se=a[cnt].se;
//			}
		} else if (cnt && x[i]==a[cnt].se+1) a[cnt].se++;
		else a[++cnt]=make_pair(x[i],x[i]),num[cnt]=1;
	}

	int ans=1;
	for (int i=1;i<=cnt;i++){
		a[i].fi=max(a[i].fi,1ll);
		a[i].se=min(a[i].se,n);
		ans=ans*num[i]%tt;
		if (i!=1 && a[i].fi<=a[i-1].se) ans=(ans-(a[i-1].se-a[i].fi+1)+tt)%tt;
	}
	printf("%lld\n",ans);
	return 0;
}
