// F**K THE PROBLEM!!!

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define int long long

const int maxn=505,maxm=105;

int n,m,W,q;
int INF;
int f[maxn][maxm];

struct gong{
	int x,t;
};
gong a[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

namespace TreeArr{
	int tree[maxm][maxn];

	inline int lowbit(int x){
		return x&(-x);
	}

	inline void update(int x,int delta,int k){
		while (x<=n){
			tree[k][x]+=delta;
			x+=lowbit(x);
		}
	}
	
	inline int query(int x,int k){
		// if (x<0) return 0;
		int ret=0;
		while (x){
			ret+=tree[k][x];
			x-=lowbit(x);
		}
		return ret;
	}
	inline int query(int L,int R,int k){
		if (L<1) L=1;
		// printf("Query [%lld,%lld] (k=%lld) = %lld\n",L,R,k,query(R,k)-query(L-1,k));
		return query(R,k)-query(L-1,k);
	}
}

signed main(){
	freopen("qinggong.in","r",stdin);
	freopen("qinggong.out","w",stdout);
	n=read();m=read();W=read();
	for (int i=1;i<=m;i++) a[i].x=read(),a[i].t=read();
	q=read();
	if (q!=0) return printf("-1\n"),0;
	for (int i=1;i<=q;i++){
		int x=read(),ki=read();
		TreeArr::update(x,1,ki);
	}
	
	memset(f,0x3f,sizeof(f));INF=f[0][0];
	for (int i=1;i<=m;i++) f[0][i]=0;
	for (int j=1;j<=m;j++){
		for (int i=0;i<=n-a[j].x;i++){
			for (int k=1;k<=m;k++){
				if (TreeArr::query(i,i+a[j].x,j)==0) f[i+a[j].x][j]=min(f[i+a[j].x][j],f[i][k]+a[j].t+((j==k)?(0):(W)));
			}
		}
	}
	int ans=INF;
	for (int i=1;i<=m;i++) ans=min(ans,f[n][i]);
	printf("%lld\n",(ans==INF)?-1:ans);
	return 0;
}