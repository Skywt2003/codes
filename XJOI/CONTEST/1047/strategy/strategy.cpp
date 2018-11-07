#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define int long long

using namespace std;

const int maxn=4005;
int n,k,sum=0;
int a[maxn],b[maxn];
vector<pair<int,int> > sub;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline bool cmp(pair<int,int> aa,pair<int,int> bb){
	return aa.second<bb.second;
}

signed main(){
	n=read();k=read();
	sub.clear();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read(),sum+=b[i],sub.push_back(make_pair(i,a[i]-b[i]));
	sort(sub.begin(),sub.end(),cmp);
	for (int i=1;i<=n;i++){
		int now=sum-b[i];
		int cnt=0;
		for (int j=0;j<(int)sub.size() && cnt<k;j++){
			if (sub[j].first!=i && sub[j].second<0) now+=sub[j].second,cnt++; else
			if (sub[j].second >= 0) break;
		}
		printf("%lld ",now);
	}
	printf("\n");
	return 0;
}