#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1000005;

int n,m;
int a[maxn];
int num[maxn];

class PST{
	#define mid (((tr-tl)>>1)+tl)

	private:
		int ls[maxn],rs[maxn];
		int pre[maxn],suf[maxn],sum[maxn];
		int tot;

	public:
		int root[maxn];

		PST(){
			tot=0;
			memset(root,0,sizeof(root));
		}

		void build(int tl,int tr,int &p,int init_value){
			p=++tot;
			if (tl==tr){
				sum[p]=pre[p]=suf[p] = init_value;
				#ifdef EBUG
					printf("p=%lld init_value=%lld\n",p,init_value);
				#endif
				return;
			}
			build(tl,mid,ls[p],init_value);
			build(mid+1,tr,rs[p],init_value);
			sum[p]=sum[ls[p]]+sum[rs[p]];
			pre[p]=max(pre[ls[p]],sum[ls[p]]+pre[rs[p]]);
			suf[p]=max(suf[rs[p]],suf[ls[p]]+sum[rs[p]]);
			#ifdef EBUG
				printf("sum[%lld] = %lld\n",p,sum[p]);
			#endif
		}

		void update(int tl,int tr,int &p,int lastp,int x,int delta){
			p=++tot;
			ls[p]=ls[lastp];
			rs[p]=rs[lastp];
			if (tl==tr){
				sum[p]=pre[p]=suf[p] = sum[lastp]+((tl==x)?delta:0);
				return;
			}
			if (x<=mid  ) update(tl,mid,ls[p],ls[lastp],x,delta);
			if (mid+1<=x) update(mid+1,tr,rs[p],rs[lastp],x,delta);
			sum[p]=sum[ls[p]]+sum[rs[p]];
			pre[p]=max(pre[ls[p]],sum[ls[p]]+pre[rs[p]]);
			suf[p]=max(suf[rs[p]],suf[ls[p]]+sum[rs[p]]);
		}

		int query_sum(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return sum[p];
			int ret=0;
			if (sl<=mid  ) ret+=query_sum(sl,sr,tl,mid,ls[p]);
			if (mid+1<=sr) ret+=query_sum(sl,sr,mid+1,tr,rs[p]);
			return ret;
		}

		int query_pre(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return pre[p];
			if (sl<=mid && mid+1<=sr){
				int sum1=query_sum(sl,sr,tl,mid,ls[p]);
				int pre1=query_pre(sl,sr,tl,mid,ls[p]);
				int pre2=query_pre(sl,sr,mid+1,tr,rs[p]);
				return max(sum1+pre2,pre1);
			} else if (sl<=mid) return query_pre(sl,sr,tl,mid,ls[p]);
			else if (mid+1<=sr) return query_pre(sl,sr,mid+1,tr,rs[p]);
		}

		int query_suf(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return suf[p];
			if (sl<=mid && mid+1<=sr){
				int suf1=query_suf(sl,sr,tl,mid,ls[p]);
				int suf2=query_suf(sl,sr,mid+1,tr,rs[p]);
				int sum2=query_sum(sl,sr,mid+1,tr,rs[p]);
				return max(suf1+sum2,suf2);
			} else if (sl<=mid) return query_suf(sl,sr,tl,mid,ls[p]);
			else if (mid+1<=sr) return query_suf(sl,sr,mid+1,tr,rs[p]);
		}

	#undef mid
};

PST t;
int cnt=0;
vector<pair<int,int> > vec;

bool compare_first(pair<int,int> aa,pair<int,int> bb){
	return aa.first < bb.first;
}

bool check(int x,int l1,int l2,int r1,int r2){
	#ifdef EBUG
		printf("Checking: %lld  [%lld,%lld] - [%lld,%lld]\n",x,l1,l2,r1,r2);
		printf("%lld,%lld,%lld\n",
			t.query_suf(l1,l2,1,n,t.root[x-1]) ,
			t.query_sum(l2+1,r1-1,1,n,t.root[x-1]) ,
			t.query_pre(r1,r2,1,n,t.root[x-1]));

		if ((t.query_suf(l1,l2,1,n,t.root[x-1]) +
			t.query_sum(l2+1,r1-1,1,n,t.root[x-1]) +
			t.query_pre(r1,r2,1,n,t.root[x-1])) >= 0) printf("TRUE\n"); else printf("FALSE\n");
	#endif

	return (t.query_suf(l1,l2,1,n,t.root[x-1]) +
			t.query_sum(l2+1,r1-1,1,n,t.root[x-1]) +
			t.query_pre(r1,r2,1,n,t.root[x-1])) >= 0;
}

signed main(){
	#ifdef EBUG
		freopen("data.in","r",stdin);
		// freopen("my.out","w",stdout);
	#endif

	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),vec.push_back(make_pair(a[i],i));
	sort(vec.begin(),vec.end(),compare_first);

	t.build(1,n,t.root[0],1);
	for (int i=0,j;i<vec.size();i=j+1){
		j=i;cnt++; num[cnt]=vec[i].first;
		t.update(1,n,t.root[cnt],t.root[cnt-1],vec[i].second,-2);
		while (j+1<vec.size() && vec[j+1].first==vec[i].first)
			j++,t.update(1,n,t.root[cnt],t.root[cnt],vec[j].second,-2);
	}

	#ifdef EBUG
		printf("\nDEBUG INFO:\n");
		for (int i=1;i<=n;i++) printf("%lld ",t.root[i]); printf("\n");
		for (int i=0;i<=cnt;i++){
			for (int j=1;j<=n;j++)
				printf("% 4lld ",t.query_sum(j,j,1,n,t.root[i]));
			printf("\n");
		}
		printf("\n");
	#endif

	#define mid (((R-L)>>1)+L)

	m=read();
	while (m--){
		int l1=read(),l2=read(),r1=read(),r2=read();
		int L=1,R=cnt,ans=-1;
		while (L<=R){
			if (check(mid,l1,l2,r1,r2)) ans=mid,L=mid+1; else R=mid-1;
		}
		#ifdef EBUG
			printf("ans=%lld\n",ans);
			if (ans==-1) printf("ERROR: ans=-1\n");
		#endif
		printf("%lld\n",num[ans]);
	}

	#undef mid

	return 0;
}