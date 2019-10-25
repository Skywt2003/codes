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

const int maxn=20005;

int T;
int n,s,m,k;
int a[maxn];

bool vis[maxn];

vector<int> loop;
int sum,cnt=0;

int pre[maxn];

int que[maxn];
int head=0,tail=0;

int ans=0;

inline int nxt(int x){return (x+k)%n;}
inline int lst(int x){return (x-k+n)%n;}

void init(){
	memset(vis,0,sizeof(vis)); ans=0;
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
			loop.clear();

			int j=i; vis[i]=true;
			loop.push_back(i),sum=a[i];
			while (nxt(j)!=i) j=nxt(j),vis[j]=true,loop.push_back(j),sum+=a[j];
			#ifdef DEBUG
				printf("In loop:\n");
				for (int j=0;j<loop.size();j++) printf("%lld ",loop[j]); printf("\n");
			#endif

			int len=loop.size();
			for (int j=0;j<len;j++) loop.push_back(loop[j]);
			for (int j=0;j<loop.size();j++) pre[j]=((j>0)?pre[j-1]:0) + a[loop[j]];
			#ifdef DEBUG
				printf("Pre[]:\n");
				for (int j=0;j<2*len;j++) printf("%lld ",pre[j]); printf("\n");
			#endif
			
			int now=0,lft;
			if (sum<=0){
				head=1,tail=1; que[1]=-1;
				for (int j=0;j<2*len;j++){
					while (head<tail && que[tail]-que[head]+1 > m) head++;
					now=max(now,pre[j]-((que[head]==-1)?0:pre[que[head]]));
					while (head<=tail && pre[que[tail]] > pre[j]) tail--;
					que[++tail]=j;
				}
				ans=max(ans,now);
			} else {
				// case 1
				now=0,lft=m%len;
				if (lft){
					head=1,tail=1; que[1]=-1;
					for (int j=0;j<2*len;j++){
						while (head<tail && que[tail]-que[head]+1 > lft) head++;
						now=max(now,pre[j]-((que[head]==-1)?0:pre[que[head]]));
						#ifdef DEBUG
							printf("j=%lld head=%lld tail=%lld\n",j,head,tail);
							for (int k=head;k<=tail;k++) printf("%lld ",que[k]); printf("\n");
							printf("now=%lld\n",now);
						#endif
						while (head<=tail && pre[que[tail]] > pre[j]) tail--;
						que[++tail]=j;
					}
					#ifdef DEBUG
						printf("NOW(+)=%lld\n",now+sum*(m/len));
					#endif
					ans=max(ans,now+sum*(m/len));
				}

				#ifdef DEBUG
					printf("Case 2-----\n");
				#endif
				// case 2
				now=0;
				if (m>=len){
					head=1,tail=1; que[1]=-1;
					for (int j=0;j<2*len;j++){
						while (head<tail && que[tail]-que[head]+1 > len) head++;
						now=max(now,pre[j]-((que[head]==-1)?0:pre[que[head]]));
						while (head<=tail && pre[que[tail]] > pre[j]) tail--;
						que[++tail]=j;
					}
					#ifdef DEBUG
						printf("NOW(+)=%lld\n",now+sum*(m/len-1));
					#endif
					ans=max(ans,now+sum*(m/len-1));
				}
			}
		}

		#ifdef DEBUG
			printf("ans=%lld\n",ans);
		#endif
		printf("Case #%lld: %lld\n",cse,max(s-ans,0ll));
	}

	return 0;
}