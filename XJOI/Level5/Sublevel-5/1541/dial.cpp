#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=105;
int n;
int ans_num=0,ans_sum=0;

namespace UniSet{
	int fa[maxn];

	inline void init(int n){
		for (int i=1;i<=n;i++) fa[i]=i;
	}

	inline int getfa(int x){
		if (fa[x]==x) return x;
		fa[x]=getfa(fa[x]);
		return fa[x];
	}

	inline void merge(int x,int y){
		x=getfa(x);y=getfa(y);
		if (x!=y) fa[x]=y;
	}
}

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

struct edge{
	int x,y,w;
};
vector<edge> edges;

inline bool cmp(edge aa,edge bb){
	return aa.w<bb.w;
}

inline void Kruskal(){
	for (int i=0;i<edges.size();i++){
		int x=UniSet::getfa(edges[i].x);
		int y=UniSet::getfa(edges[i].y);
		if (x!=y){
			UniSet::fa[x]=y;
			ans_num++;
			ans_sum+=edges[i].w;
		}
	}
}

signed main(){
	n=read();
	UniSet::init(n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			int x=read();
			if (i==j) continue;
			if (x==0) UniSet::merge(i,j); else
			if (i<j) edges.push_back((edge){i,j,x});
		}
	}
	sort(edges.begin(),edges.end(),cmp);
	Kruskal();
	printf("%lld\n%lld\n",ans_num,ans_sum);
	return 0;
}