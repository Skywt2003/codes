#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int maxn=2000006;

int n,m1,m2;
pair<int,int> a[maxn],b[maxn],c[maxn];
pair<int,int> aa[maxn],bb[maxn],cc[maxn];

int ans1=0,ans2=0;

bool compare_first(pair<int,int> aa,pair<int,int> bb){
	return aa.first > bb.first;
}

bool compare_first2(pair<int,int> aa,pair<int,int> bb){
	return aa.first < bb.first;
}

signed main(){
	n=read(); m1=read(); m2=read();
	for (int i=1;i<=n;i++) a[i].first=read(),a[i].second=read(),aa[i]=a[i];
	for (int i=1;i<=m1;i++) b[i].first=read(),b[i].second=read(),bb[i]=b[i];
	for (int i=1;i<=m2;i++) c[i].first=read(),c[i].second=read(),cc[i]=c[i];

	sort(a+1,a+1+n,compare_first);
	sort(b+1,b+1+m1,compare_first);
	sort(c+1,c+1+m2,compare_first);

	int i=1,j=m2;
	for (;;){
		if (i>n || j<1 || a[i].first <= c[j].first) break;
		int now_num=min(a[i].second, c[j].second);
		ans1+=now_num*(a[i].first-c[j].first);
		a[i].second-=now_num; c[j].second-=now_num;
		if (a[i].second==0) i++;
		if (c[j].second==0) j--;
	}

	for (int i=1;i<=n;i++) a[i]=aa[i];
	for (int i=1;i<=m1;i++) b[i]=bb[i];
	for (int i=1;i<=m2;i++) c[i]=cc[i];
	sort(a+1,a+1+n,compare_first2);
	sort(b+1,b+1+m1,compare_first2);
	sort(c+1,c+1+m2,compare_first2);

	i=1,j=1;
	for (;;){
		if (i>m1 || j>n) break;
		while (j<=n && a[j].first < b[i].first) j++;
		if (j>n) break;
		int now_num=min(a[j].second,b[i].second);
		a[j].second-=now_num; b[i].second-=now_num;
		if (a[j].second==0) j++;
		if (b[i].second==0) i++;
	}
	if (j>n && i<=m1) ans2=-INF;

	// i=1,j=1;
	// for (;;){
	// 	if (i>n || j>m2 || c[j].first>0) break;
	// 	while (i<=n && a[i].first < c[j].first) i++;
	// 	if (i>n) break;
	// 	int now_num=min(a[i].second, c[j].second);
	// 	ans2+=now_num*(a[i].first-c[j].first);
	// 	a[i].second-=now_num; c[j].second-=now_num;
	// 	if (a[i].second==0) i++;
	// 	if (c[j].second==0) j++;
	// }
	/*
		Hack data:
		(A) -1 6
		(B) -2
 	*/

	i=n,j=1;
	for (;;){
		if (i<1 || j>m2 || c[j].first>0) break;
		while (i>=1 && a[i].first < c[j].first) i--;
		if (i<1) break;
		int now_num=min(a[i].second, c[j].second);
		ans2+=now_num*(a[i].first-c[j].first);
		a[i].second-=now_num; c[j].second-=now_num;
		if (a[i].second==0) i--;
		if (c[j].second==0) j++;
	}
	for (int i=1;i<=n;i++) if (a[i].first>0) ans2+=a[i].first*a[i].second;

	printf("%lld\n",max(ans1,ans2));
	return 0;
}