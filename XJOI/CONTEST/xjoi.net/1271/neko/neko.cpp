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
		inline void init(int n){for (int i=0;i<n;i++) fa[i]=i,sum[i]=a[i],cnt[i]=1;}

		inline int getcnt(int x){return cnt[getfa(x)];}
		inline int getsum(int x){return sum[getfa(x)];}
		
		inline int getfa(int x){return (fa[x]==x)?x:fa[x]=getfa(fa[x]);}
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

inline int nxt(int x){return (x+k)%n;}
inline int lst(int x){return (x-k+n)%n;}

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
			printf("getsum(1)=%lld\n",u.getsum(1));
		#endif
		memset(vis,0,sizeof(vis));

		for (int i=0;i<n;i++) if (!vis[i]){
			int cnt=u.getcnt(i),sum=u.getsum(i);
			int now=max(0ll,(m/cnt)*sum); ans=max(ans,now);
			int lft=m%cnt;

			int head=i,tail=i,allsum=0,delta=0;

			cnt--; vis[head]=true;
			int tmp1=lft,tmp2=i;
			while (tmp1--){
				allsum+=a[tmp2];
				if (allsum > delta) delta=allsum,tail=tmp2;
				tmp2=nxt(tmp2);
			}
			ans=max(ans,now+delta);

			#ifdef DEBUG
				printf("head=%lld tail=%lld delta=%lld allsum=%lld\n",head,tail,delta,allsum);
			#endif
			while (cnt--){
				head=nxt(head); vis[head]=true;
				delta-=a[lst(head)];
				if (tail==lst(head)){
					tail=head; delta=a[head];
					int tmp1=cnt,tmp2=head,tmp3=0;
					while (tmp1--){
						tmp3+=a[tmp2];
						if (tmp3 > delta) delta=tmp3,tail=tmp2;
						tmp2=nxt(tmp2);
					}
				}
				allsum=allsum - a[lst(head)] + a[(head+(lft-1)*k)%n];
				if (allsum > delta) delta=allsum,tail=(head+(lft-1)*k)%n;

				ans=max(ans,now+delta);

				#ifdef DEBUG
					printf("head=%lld tail=%lld delta=%lld allsum=%lld\n",head,tail,delta,allsum);
				#endif
			}
		}

		printf("Case #%lld: %lld\n",cse,max(s-ans,0ll));
		#ifdef DEBUG
			printf("ans=%lld\n",ans);
		#endif
	}

	return 0;
}