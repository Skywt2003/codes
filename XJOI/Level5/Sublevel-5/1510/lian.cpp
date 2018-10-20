#include<cstdio>
#include<cstring>
#include<iostream>

#define int long long
using namespace std;

const int maxn=100005;
int n,m,fa[maxn],rnk[maxn],ans=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

namespace UniSet{
	inline int getfa(int x){
		if (fa[x]==x) return x;
		int f=fa[x];
		fa[x]=getfa(fa[x]); //路径压缩
		rnk[x]=(rnk[x]+rnk[f])%3;
		return fa[x];
	}
}

inline bool check(int k,int x,int y){
	if (x>n||y>n) return false;
	if (k==2&&x==y) return false;
	int fx=UniSet::getfa(x),fy=UniSet::getfa(y);
	if (k==1){
		if (fx==fy){
			if (rnk[x]!=rnk[y]) return false;
		} else {
			fa[fx]=fy;
			rnk[fx]=(rnk[y]-rnk[x]+3)%3;
			UniSet::getfa(x);UniSet::getfa(y);
		}
	} else {
		if (fx==fy){
			if (rnk[x]==1&&rnk[y]!=0) return false;
			if (rnk[x]==2&&rnk[y]!=1) return false;
			if (rnk[x]==0&&rnk[y]!=2) return false;
		} else {
			fa[fx]=fy;
			rnk[fx]=(rnk[y]-rnk[x]+3+1)%3;
			UniSet::getfa(x);UniSet::getfa(y);
		}
	}
	return true;
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		int z=read(),x=read(),y=read();
		if (!check(z,x,y)) ans++;
	}
	printf("%lld\n",ans);
	return 0;
}