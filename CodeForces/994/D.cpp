#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn=20;
int n,m,ans=1;
pair <int,int> a[maxn],b[maxn];
bool is[15];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int have_same(pair<int,int> aa, pair<int,int> bb){
	// cout<<aa.first<<","<<aa.second<<"  "<<bb.first<<","<<bb.second<<endl;
	if (aa.first==bb.first && aa.first!=bb.second && aa.second!=bb.first && aa.second!=bb.second) return aa.first;
	if (aa.first!=bb.first && aa.first==bb.second && aa.second!=bb.first && aa.second!=bb.second) return aa.first;
	if (aa.first!=bb.first && aa.first!=bb.second && aa.second==bb.first && aa.second!=bb.second) return aa.second;
	if (aa.first!=bb.first && aa.first!=bb.second && aa.second!=bb.first && aa.second==bb.second) return aa.second;
	// cout<<"NO"<<endl;
	return -1;
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read();
		a[i]=make_pair(x,y);
	}
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		b[i]=make_pair(x,y);
	}

	bool tmp[15];
	for (int i=1;i<=n;i++){
		int cnt=0;
		memset(tmp,0,sizeof(tmp));
		for (int j=1;j<=m;j++){
			int now=have_same(a[i],b[j]);
			is[now]=true;tmp[now]=true;
		}
		for (int j=1;j<=9;j++) cnt+=tmp[j];
		if (cnt>1){
			cout<<-1<<endl;
			return 0;
		}
	}

	for (int i=1;i<=m;i++){
		int cnt=0;
		memset(tmp,0,sizeof(tmp));
		for (int j=1;j<=n;j++){
			int now=have_same(a[j],b[i]);
			tmp[now]=true;
		}
		for (int j=1;j<=9;j++) cnt+=tmp[j];
		if (cnt>1){
			cout<<-1<<endl;
			return 0;
		}
	}

	int all_cnt=0;
	for (int i=1;i<=9;i++) {all_cnt+=is[i];if (is[i]) ans=i;}
	if (all_cnt>1) cout<<0<<endl; else cout<<ans<<endl;
	return 0;
}