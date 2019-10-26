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

const int maxn=1e5+5;

int n;

int tot=0,lnk[maxn],nxt[2*maxn],to[2*maxn];
int fa[maxn],siz[maxn];
int deep[maxn],sum[maxn];

int ans=INF;

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_tree(int x){
	siz[x]=1;
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		fa[to[i]]=x; deep[to[i]]=deep[x]+1;
		build_tree(to[i]);
		siz[x]+=siz[to[i]];
		sum[x]+=sum[to[i]]+siz[to[i]];
	}
	#ifdef DEBUG
		printf("size[%lld]=%lld, sum[%lld]=%lld\n",x,siz[x],x,sum[x]);
	#endif
}

int que[maxn];
int que_num[maxn],que_sum[maxn];

void DFS(int x,int ctrl,int uninc,int inc){
	#ifdef DEBUG
		printf("x=%lld ctrl=%lld uninc=%lld inc=%lld\n",x,ctrl,uninc,inc);
	#endif
	ans=min(ans,uninc+inc + sum[x] +siz[x]+ctrl); // because the weight of added edge is 1
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		int nuninc=uninc,nctrl=ctrl,ninc=inc;

		que[++que[0]]=to[i];
		que_num[que[0]-1]=siz[x]-siz[to[i]],
		que_sum[que[0]-1]=sum[x]-(sum[to[i]]+siz[to[i]]);

		ninc+=nctrl;
		nctrl+=que_num[que[0]-1],
		ninc+=que_sum[que[0]-1] + que_num[que[0]-1];

		if (que[0]&1)
			nctrl-=que_num[(que[0]+1)>>1],
			nuninc+=que_sum[(que[0]+1)>>1] + que_num[(que[0]+1)>>1]*(que[0]>>1),
			ninc-=que_sum[(que[0]+1)>>1] + que_num[(que[0]+1)>>1]*(que[0]>>1);
		if (que[0]==2)
			nctrl-=que_num[1],
			nuninc+=que_sum[1],
			ninc-=que_sum[1] + que_num[1];
		DFS(to[i],nctrl,nuninc,ninc);

		que[0]--;
	}
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}

	build_tree(1);

	ans=min(ans,sum[1]);
	que[++que[0]]=1;
	DFS(1,0,0,0);

	printf("%lld\n",ans);
	return 0;
}