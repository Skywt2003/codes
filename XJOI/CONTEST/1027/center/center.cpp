#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005,maxe=1000005;
int n,m,q;
int dst[maxn][maxn];
vector<int> lnk[maxn];

struct bitset{
	static const int maxn=35,maxm=30;
	int set[maxn];

	inline void clear(){
		memset(set,0,sizeof(set));
	}

	inline bool operator [](int index){
		index--;
		return (set[index/maxm]>>index%maxm)&1;
	}

	inline void set_value(int index,int value){
		index--;
		if (value) set[index/maxm]|=(int)1<<index%maxm; else set[index/maxm]&=~((int)1<<index%maxm);
	}

	inline void merge(bitset &b){
		for (int i=0;i<maxn;i++) set[i]|=b.set[i];
	}

	inline int count(){
		int ret=0;
		for (int i=0;i<maxn;i++) ret+=__builtin_popcount(set[i]);
		return ret;
	}
};
bitset v[maxn][maxn];

namespace Graph{
	queue<int> que;
	bool vis[maxn];

	inline void init(){
		while (!que.empty()) que.pop();
		memset(vis,0,sizeof(vis));
	}

	inline void BFS(int s){
		memset(dst[s],0x3f,sizeof(dst[s]));
		for (int i=0;i<=n;i++) v[s][i].clear();
		que.push(s);vis[s]=true;dst[s][s]=0;v[s][0].set_value(s,true);
		while (!que.empty()){
			int head=que.front();que.pop();
			for (int is=0;is<lnk[head].size();is++){
				int now=lnk[head][is];
				if (!vis[now]){
					dst[s][now]=dst[s][head]+1;
					v[s][dst[s][now]].set_value(now,true);
					vis[now]=true;que.push(now);
				}
			}
		}
		for (int i=1;i<=n;i++) v[s][i].merge(v[s][i-1]);
	}
}

signed main(){
	n=read();m=read();q=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		lnk[x].push_back(y);
		lnk[y].push_back(x);
	}

	for (int i=1;i<=n;i++) Graph::init(),Graph::BFS(i);

	while (q--){
		int k=read();
		bitset ans;ans.clear();
		int a_now,d_now;
		for (int i=1;i<=k;i++) a_now=read(),d_now=read(),ans.merge(v[a_now][d_now]);
		printf("%lld\n",ans.count());
	}
	return 0;
}