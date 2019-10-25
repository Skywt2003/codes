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
const int NEG_INF=0x8080808080808080;

const int maxn=10005;

int T;
int n,s,m,k;
int a[maxn];

class uniset{
	private:
		int fa[maxn],sum[maxn],cnt[maxn];

	public:
		inline void init(int n){
			for (int i=0;i<n;i++) fa[i]=i,sum[i]=a[i],cnt[i]=1;
		}

		inline int getfa(int x){
			return (fa[x]==x)?x:fa[x]=getfa(fa[x]);
		}

		inline int getcnt(int x){
			return cnt[getfa(x)];
		}

		inline int getsum(int x){
			return sum[getfa(x)];
		}
		
		void merge(int x,int y){
			x=getfa(x),y=getfa(y);
			if (x==y) return;
			fa[x]=y;
			sum[y]+=sum[x],sum[x]=0;
			cnt[y]+=cnt[x],cnt[x]=0;
		}
};

bool vis[maxn];
uniset u;

inline void init(){
	memset(vis,0,sizeof(vis));
	u.init(n);
}

inline int nxt(int x){
	return (x+k)%n;
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	T=read();
	for (int cse=1;cse<=T;cse++){
		n=read();s=read();m=read();k=read();
		for (int i=0;i<n;i++) a[i]=read();
		init();

		int ans=0;
		for (int i=0;i<n;i++) if (!vis[i]){
			int j=i; vis[j]=true;
			while (nxt(j)!=i) j=nxt(j),vis[j]=true,u.merge(i,j);
		}

		#ifdef DEBUG
			printf("Prebuild OK\n");
		#endif

		for (int i=0;i<n;i++){
			int now=max(0ll,m/u.getcnt(i)*u.getsum(i));

			int j=i,lft=(m/u.getcnt(i)*u.getsum(i)<0)?m-1:m%u.getcnt(i);
			if (m==u.getcnt(i)) now=0,lft=m;
			ans=max(ans,now);
			while (lft--) now+=a[j],j=nxt(j),ans=max(ans,now);
			#ifdef DEBUG
				printf("i=%lld now=%lld\n",i,now);
			#endif
		}

		printf("Case #%lld: %lld\n",cse,max(s-ans,0ll));
	}

	return 0;
}