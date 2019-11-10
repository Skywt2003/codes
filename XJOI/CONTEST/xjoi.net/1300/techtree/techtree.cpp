#include<bits/stdc++.h>

#define int long long

using namespace std;

int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=998244353;
const int maxn=1005;

int qsm(int a,int b){
	int ret=1,w=a;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt; b>>=1;
	}
	return ret;
}

inline int inv(int a){
	return qsm(a,tt-2);
}

int n,m;
int fa[maxn],p[maxn];

int ans=0;
bool vis[maxn];

int tot=0,lnk[maxn],nxt[maxn],to[maxn];
bool leaf[maxn];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

// p[i]=0 -> i is finalTec.
void DFS(int x,int nowp){
	int sum=0;
	for (int i=2;i<=n;i++) if (!vis[i] && vis[fa[i]]) sum=(sum+p[i])%tt;
	for (int i=2;i<=n;i++) if (!vis[i] && vis[fa[i]]){
		if (leaf[i] && i!=m) continue; else
		if (leaf[i] && i==m) ans=(ans+nowp*p[i]%tt*inv(sum)%tt)%tt; else {
			vis[i]=true;
			DFS(i,nowp*p[i]%tt*inv(sum)%tt);
			vis[i]=false;
		}
	}
}

void build_tree(int x){
	if (lnk[x]==0) p[x]=1,leaf[x]=true;
	for (int i=lnk[x];i;i=nxt[i]) build_tree(to[i]),p[x]+=p[to[i]];
}

bool subtask3=true,subtask4=true;

signed main(){
	freopen("techtree.in","r",stdin);
	freopen("techtree.out","w",stdout);
	n=read();m=read();
	for (int i=2;i<=n;i++){
		fa[i]=read(),add_edge(fa[i],i);
		if (fa[i]!=1) subtask3=false;
		if (fa[i]!=i-1) subtask4=false;
	}
	if (subtask3){
		printf("%lld\n",inv(n-1));
		return 0;
	} else if (subtask4){
		printf((m==n)?"1\n":"0\n");
		return 0;
	}
	build_tree(1);
	
	vis[1]=true;
	DFS(1,1);
	
	printf("%lld\n",ans);
	return 0;
}
