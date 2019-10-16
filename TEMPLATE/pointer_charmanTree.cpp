// Persistence Segment Tree

// 沉迷指针 无法自拔

#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

class PST{
	#define mid (((tr-tl)>>1)+tl)

	private:
		struct Node{
			Node *ls,*rs;
			int value;

			Node(){
				ls=rs=NULL;
				value=0;
			}
		};

	public:
		Node *root[maxn];

		void build(Node *&now,int tl,int tr){ // 建立第一棵空树
			now=new Node;
			if (tl==tr) return;
			build(now->ls,tl,mid);
			build(now->rs,mid+1,tr);
		}

		void update(Node *&now,Node *&last,int tl,int tr,int x){
			now=new Node;
			now->ls=last->ls;
			now->rs=last->rs;
			now->value=last->value+1;
			if (tl==tr) return;
			if (x<=mid  ) update(now->ls,last->ls,tl,mid,x); else
			if (mid+1<=x) update(now->rs,last->rs,mid+1,tr,x);
		}

		int query(Node *&sl,Node *&sr,int tl,int tr,int x,vector<int> &a){ // 传入 a 数组
			if (tl==tr) return a[tl-1];
			int lft=sr->ls->value - sl->ls->value;
			if (lft>=x) return query(sl->ls,sr->ls,tl,mid,x,a);
			else return query(sl->rs,sr->rs,mid+1,tr,x-lft,a);
		}
};

int n,m;
int a[maxn];

PST tree;

vector<int> vec;

signed main(){
	n=read();m=read();vec.clear();
	for (int i=1;i<=n;i++) a[i]=read(),vec.push_back(a[i]);

	sort(vec.begin(),vec.end());
	auto bg=vec.begin();
	auto ed=unique(vec.begin(),vec.end());

	int up=distance(bg,ed);
	tree.build(tree.root[0],1,up);

	for (int i=1;i<=n;i++){
		auto now=lower_bound(bg,ed,a[i]);
		tree.update(tree.root[i],tree.root[i-1],1,up,distance(bg,now)+1);
	}

	while (m--){
		int L=read(),R=read(),k=read();
		printf("%d\n",tree.query(tree.root[L-1],tree.root[R],1,up,k,vec));
	}

	return 0;
}