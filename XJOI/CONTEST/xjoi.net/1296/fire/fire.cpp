#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}


const int maxn=3e5+5;

int n,T,q;
int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2],w[maxn*2];

void add_edge(int x,int y,int z){
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

namespace subtask_chain{ // ONLINE!!!
	int wet[maxn],sum[maxn];

	void build_STtable(){
		
	}

	void query_RMQ(int x,int y){
		
	}

	int query(int x,int y){
		int L=x,R=n-1;
		while (L<=R){
			
		}
	}

	signed main(){
		n=read(),T=read();
		for (int i=1;i<n;i++){
			read();
			wet[i]=read(),sum[i]=sum[i-1]+wet[i];
		}
		build_STtable;
		
		q=read();
		int lastans=0;
		while (q--){
			int x=read(),y=read();
			x^=lastans%(1ll<<20),y^=lastans%(1ll<<20);
			printf("%lld\n",lastans=query(x,y));
		}
		return 0;
	}
};

namespace subtask_offline{
	struct edge{
		int x,y,w;
		bool operator <(edge bb)const{return w<bb.w;}
		bool operator >(edge bb)const{return w>bb.w;}
	};
	edge e[maxn];

	int id[maxn],siz[maxn],top[maxn];

	class bitIndexTree{
		private:
			int tree[maxn];
			int lowbit(int x){
				return x&(-x);
			}
			
		public:
			void update(int x,int delta){
				while (x<=n) tree[x]+=delta,x+=lowbit(x);
			}
			
			int query(int x){
				int ret=0;
				while (x) ret+=tree[x],x-=lowbit(x);
				return ret;
			}
			
			int query(int x,int y){
				return query(y)-query(x-1);
			}
	};
	bitIndexTree t;
	
	struct query{int x,w,ans,id;};
	query qs[maxn];
	bool compare_query_w(query aa,query bb){return aa.w < bb.w;}
	bool compare_query_id(query aa,query bb){return aa.id < bb.id;}
	
	void build_tree(int x,int fa){
		id[x]=++id[0]; siz[x]=1;
		for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
			top[i+1>>1]=x;
			build_tree(to[i],x);
			siz[x]+=siz[to[i]];
		}
	}
	
	const int INF=0x000000003f3f3f3f;
	
	signed main(){
		n=read(); T=read();
		if (T!=0) {printf("FUCK YOU!!!\n");return 0;}
		for (int i=1;i<n;i++){
			e[i].x=read(),e[i].y=read(),e[i].w=read();
			add_edge(e[i].x,e[i].y,e[i].w);
			add_edge(e[i].y,e[i].x,e[i].w);
		}
		sort(e+1,e+n);
		build_tree(1,-1);
		for (int i=1;i<=n;i++) t.update(i,-INF);
		
		q=read();
		for (int i=1;i<=q;i++) qs[i].x=read(),qs[i].w=read(),qs[i].id=i;
		sort(qs+1,qs+1+q,compare_query_w);
		
		int j=0;
		for (int i=1;i<=q;i++){
			while (e[j+1].w <= qs[i].w) j++,t.update(top[j],e[j].w+INF);
			int L=id[qs[i].x],R=id[qs[i].x]+siz[qs[i].x]-1;
			#define mid (((R-L)>>1)+L)
			while (L<=R){
				int now=t.query(qs[i].x,mid);
				if (now > 0) qs[i].ans=now,L=mid+1; else R=mid-1;
			}
			#undef mid
		}
		sort(qs+1,qs+1+q,compare_query_id);
		for (int i=1;i<=q;i++) printf("%lld\n",qs[i].ans);
		return 0;
	}
};

int testCaseId;

signed main(){
	testCaseId=read();
	if (9<=testCaseId && testCaseId<=12) return subtask_chain::main();
	return subtask_offline::main();
}
