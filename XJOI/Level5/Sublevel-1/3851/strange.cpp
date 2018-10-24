#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define int long long
using namespace std;

const int INF=1e10;
const int maxn=105;
int n,oud[maxn];
bool f[maxn][maxn];

vector<pair<int,int> > vec;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline bool cmp(pair<int,int> aa,pair<int,int> bb){
	return aa.first<bb.first;
}

signed main(){
	n=read();
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++) oud[i]=read();
	for (int i=1;i<=n;i++) vec.push_back(make_pair(oud[i],i));

	for (int i=1;i<=n;i++) f[i][i]=true;
	for (int i=0;i<n-1;i++){
		sort(vec.begin(),vec.end(),cmp);
		int now=vec[0].second;
		int cnt=n-vec[0].first-1 -i;
		for (int j=1;j<=cnt;j++){
			vec[n-i-j].first--;
			f[vec[n-i-j].second][now]=true;
		}
		for (int j=1;j<n-i-cnt;j++) f[now][vec[j].second]=true;
		vector<pair<int,int> > nxt;nxt.clear();
		for (int j=1;j<vec.size();j++) nxt.push_back(vec[j]);
		vec=nxt;
	}

	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++) if (k!=i)
			for (int j=1;j<=n;j++) if (k!=j&&i!=j)
				f[i][j]|=f[i][k]&&f[k][j];
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			ans+=f[i][j];
			// if (f[i][j]) printf("%lld => %lld\n",i,j);
		}
	printf("%lld\n",ans);
	return 0;
}