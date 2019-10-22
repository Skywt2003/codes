#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;

int n,p,ans[maxn];

struct node{
	int t,id;

	bool operator <(node bb)const{
		return id > bb.id;
	}
	bool operator >(node bb)const{
		return id < bb.id;
	}
};

node b[maxn];
deque<node> que;
priority_queue<node> heap;

bool compare_s(node aa,node bb){
	return (aa.t<bb.t)||(aa.t==bb.t && aa.id<bb.id);
}

class indexTree{
	private:
		int tree[maxn];

		int lowbit(int x){
			return x&(-x);
		}

	public:
		indexTree(){
			memset(tree,0,sizeof(tree));
		}

		void update(int x,int delta){
			while (x<=n) tree[x]+=delta,x+=lowbit(x);
		}

		int query(int x){
			int ret=0;
			while (x) ret+=tree[x],x-=lowbit(x);
			return ret;
		}
};
indexTree t;

signed main(){
	n=read(),p=read();
	for (int i=1;i<=n;i++) b[i]=(node){read(),i};

	sort(b+1,b+1+n,compare_s);
	while (!heap.empty()) heap.pop();
	while (!que.empty()) que.pop_back();

	int nowt=0;
	for (int i=1;i<=n;i++){
		while (!que.empty() && que.front().t+p <= b[i].t){
			nowt=max(nowt+p, que.front().t+p);
			ans[que.front().id]=nowt,
			t.update(que.front().id,1),
			que.pop_front();
		}
		while (!heap.empty() && t.query(heap.top().id-1)==0)
			que.push_back(heap.top()),heap.pop();
		if (t.query(b[i].id-1) == 0)
			que.push_back(b[i]),
			t.update(b[i].id,-1);
		else heap.push(b[i]);
	}

	while ((!heap.empty()) || (!que.empty())){
		if (!que.empty()){
			nowt=max(nowt+p,que.front().t+p);
			ans[que.front().id]=nowt;
			t.update(que.front().id,1);
			que.pop_front();
		}
		#ifdef EBUG
			if (!heap.empty())
				printf("TOP QUERY: %lld\n",t.query(heap.top().id-1));
			else printf("Heap empty\n");
		#endif
		while (!heap.empty() && t.query(heap.top().id-1)==0)
			que.push_back(heap.top()),heap.pop();
	}

	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}