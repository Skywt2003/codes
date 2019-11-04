#include<bits/stdc++.h>
#define int long long

using namespace std;
#define pii pair<int,int>

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;

int n,p,ans[maxn];

priority_queue<pii,vector<pii>,greater<pii> > heap; // pair<time,id>
queue<int> que;
set<int> want;

signed main(){
	n=read(),p=read();
	for (int i=1;i<=n;i++) heap.push(make_pair(read(),i));

	int nowt=0;
	for (int i=1;i<=n;i++){
		if (que.empty() && want.empty()) nowt=heap.top().first;
		nowt+=p;
		while (!heap.empty() && heap.top().first <= nowt){
			if (que.empty() || que.back() > heap.top().second) que.push(heap.top().second);
			else want.insert(heap.top().second);
			heap.pop();
		}
		ans[que.front()]=nowt; que.pop();
		if (que.empty() && !want.empty()) que.push(*want.begin()),want.erase(want.begin());
	}

	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}