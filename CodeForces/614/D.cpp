#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005;

int n,A,cj,cm,m;
pair<int,int> a[maxn];
int sum[maxn];
int ans=0,ansx=-1,ansy=-1;

inline bool cmp_value(pair<int,int> aa,pair<int,int> bb){
	return aa.first<bb.first;
}

inline bool cmp_id(pair<int,int> aa,pair<int,int> bb){
	return aa.second<bb.second;
}

inline int get_all_sum(int x,int up){
	int L=1,R=up;
	int ret=0;
	while (L<=R){
		int mid=((R-L)>>1)+L;
		if (a[mid].first>x) R=mid-1; else ret=x*mid-sum[mid],L=mid+1;
	}
	return ret;
}

signed main(){
	n=read();A=read();cj=read();cm=read();m=read();
	for (int i=1;i<=n;i++) a[i].first=read(),a[i].second=i;
	sort(a+1,a+1+n,cmp_value);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].first;
	int need=0;
	for (int i=n+1;i>=1;i--){
		if (i<=n) need+=A-a[i].first;
		if (need>m) break;
		int L=0,R=A;
		while (L<=R){
			int mid=((R-L)>>1)+L;
			int all_sum=get_all_sum(mid,i-1);
			if (all_sum > m-need) R=mid-1; else {
				if ((n-i+1)*cj+mid*cm>ans){
					ans=(n-i+1)*cj+mid*cm;
					ansx=mid;ansy=i;
				}
				L=mid+1;
			}
		}
	}
	printf("%lld\n",ans);
	if (ansx!=-1 && ansy!=-1){
		for (int i=1;i<ansy;i++) a[i].first=max(ansx,a[i].first);
		for (int i=ansy;i<=n;i++) a[i].first=A;
	}
	sort(a+1,a+1+n,cmp_id);
	for (int i=1;i<=n;i++) printf("%lld ",a[i].first);printf("\n");
	return 0;
}