#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define int long long
using namespace std;

const int maxn=1e7+5;
int T;
int n,m,k,x;

vector<int> vec;
map<int,int> id;
int cnt=0,ans,now,lst;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void descret(){
	id.clear();
	sort(vec.begin(),vec.end());
	for (int i=0;i<vec.size();){
		int j=i;id[vec[i]]=++cnt;
		while (j+1<vec.size() && vec[j+1]==vec[i]) j++;
		i=j+1;
	}
}

namespace UniSet{
	int fa[maxn];

	inline int getfa(int x){
		if (fa[x]==x) return x;
		fa[x]=getfa(fa[x]);
		return fa[x];
	}

	inline void merge(int x,int y){
		x=fa[x];y=fa[y];
		if (x==y) return;
		ans--;
		fa[x]=y;
	}

	inline void init(int n){
		for (int i=1;i<=n;i++) fa[i]=i;
	}
}

signed main(){
	T=read();
	while (T--){
		n=read();m=read();
		x=read();k=read();
		vec.clear();cnt=0;
		vec.push_back(x);
		now=x;
		for (int i=1;i<2*m;i++) now=now*k%n,vec.push_back(now);
		descret();UniSet::init(cnt);
		ans=n;
		now=x,lst=-1;
		for (int i=1;i<2*m;i++){
			lst=now,now=now*k%n;
			if (i&1) UniSet::merge(id[lst],id[now]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}