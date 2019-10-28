#include<bits/stdc++.h>

#define int long long
#define pii pair<int,int>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e6+5,maxe=2e6+5;;

int n,m,k;
int c[maxn];
int d[maxn];

int tot=0,lnk[maxn],nxt[maxe],to[maxe];

int clr[maxn],cnt=0;

int c1,c2,zhijin;

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

pii get_far_dist(int x,int fa){
	pii ret=make_pair(x,0);
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
		pii now=get_far_dist(to[i],x); now.second;
		if (now.second > ret.second) ret=now;
	}
	return ret;
}

void get_zhijin(){
	pii now=get_far_dist(1,-1);
	pii nxt=get_far_dist(now.first,-1);
	c1=now.first; c2=nxt.first; zhijin=nxt.second;
}



void make_color(int x,int fa,int delta){
	if (clr[c[x]]==1 && delta==-1) cnt--;
	if (clr[c[x]]==0 && delta==1) cnt++;
	clr[c[x]]+=delta;
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa) make_color(to[i],x,delta);
}

bool DFS(int x,int fa,int dist,int toc){
	if (dist>=toc){
		make_color(x,fa,1);
		int tmp=cnt;
		make_color(x,fa,-1);
		return tmp>=k;
	}
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
		if (DFS(to[i],x,dist+1,toc)) return true;
	}
	return false;
}

vector<int> leaves;

bool check(int x){
	for (int i=0;i<leaves.size();i++) if (DFS(leaves[i],-1,0,x)) return true;
	return false;
}

int L,R,ans=-1;
#define mid (((R-L)>>1)+L)

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read(); m=read(); k=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
		d[x]++;d[y]++;
	}

	get_zhijin();
	if (m==1){
		printf("%lld\n",zhijin);
		return 0;
	}

	for (int i=1;i<=n;i++) if (d[i]==1) leaves.push_back(i);

	L=0;R=n;
	while (L<=R){
		if (check(mid)) ans=mid,L=mid+1; else R=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}

#undef mid