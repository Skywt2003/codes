#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define int long long

using namespace std;

const int maxn=6e5+10,maxe=2*maxn;

int n;
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
int f[maxn][26],deep[maxn];
int p[maxn],ans=0;
int num[maxn];
int lft[maxn],rght[maxn];
int tail=0;
pair<int,int> stk[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add_edge(int x,int y){
	tot++;son[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void build_tree(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=f[x][0]){
		f[son[i]][0]=x;deep[son[i]]=deep[x]+1;
		build_tree(son[i]);
	}
}

inline void build_lca(){
	for (int j=1;j<26;j++){
		for (int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
	}
}

inline int get_lca(int x,int y){
	if (deep[x]>deep[y]) swap(x,y);
	for (int i=25;i>=0;i--) if (deep[f[y][i]] >= deep[x]) y=f[y][i];
	if (x==y) return x;
	for (int i=25;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

signed main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}
	deep[1]=1;build_tree(1);
	build_lca();
	for (int i=1;i<=n;i++) p[i]=read();

	for (int i=1;i<=n;i++) ans+=deep[i];
	for (int i=1;i<n;i++) num[i]=deep[get_lca(p[i],p[i+1])];

	tail=1;stk[1]=make_pair(1,num[1]);
	for (int i=2;i<n;i++){
		while (tail>0 && stk[tail].second > num[i]) tail--;
		if (tail>0) lft[i]=i-stk[tail].first-1; else lft[i]=i-1;
		stk[++tail]=make_pair(i,num[i]);
	}

	tail=1;stk[1]=make_pair(n-1,num[n-1]);
	for (int i=n-2;i>=1;i--){
		while (tail>0 && stk[tail].second >= num[i]) tail--;
		if (tail>0) rght[i]=stk[tail].first-i-1; else rght[i]=n-i-1;
		stk[++tail]=make_pair(i,num[i]);
	}

	// for (int i=1;i<n;i++) printf("%lld ",num[i]);printf("\n");
	// for (int i=1;i<n;i++) printf("%lld ",lft[i]);printf("\n");
	// for (int i=1;i<n;i++) printf("%lld ",rght[i]);printf("\n");

	for (int i=1;i<n;i++) ans+=num[i]*((lft[i]+1)*(rght[i]+1));
	printf("%lld\n",ans);
	return 0;
}