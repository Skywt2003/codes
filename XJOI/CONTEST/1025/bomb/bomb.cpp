#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<map>

#define int long long
using namespace std;

const int tt=998244353;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=10;
int n,m,ans=0;
bool lnk[maxn][maxn];

namespace UniSet{
	int fa[maxn],sum[maxn];

	inline void init(int n){
		for (int i=1;i<=n;i++) fa[i]=i,sum[i]=1;
	}

	inline int getfa(int x){
		if (fa[x]==x) return x;
		fa[x]=getfa(fa[x]);
		return fa[x];
	}

	inline void merge(int x,int y){
		x=getfa(x),y=getfa(y);
		if (x!=y) fa[y]=x,sum[x]+=sum[y],sum[y]=0;
	}
}

inline bool check(){
	UniSet::init(n);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (lnk[i][j]) UniSet::merge(i,j);
	int now=0;
	for (int i=1;i<=n;i++){
		int f=UniSet::getfa(i);
		if (UniSet::sum[f]>now) now=UniSet::sum[f];
	}
	return now==m;
}

inline void DFS(int x,int i){
	if (x==n-1 && i==n){
		ans+=check();
		return;
	}
	if (i==n) x++,i=x+1; else i++;
	lnk[x][i]=true;
	DFS(x,i);
	lnk[x][i]=false;
	DFS(x,i);
}

signed main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	n=read();m=read();
	DFS(0,0);
	printf("%lld\n",ans);
	return 0;
}