#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
#define int long long

const int maxn=1e5+5,maxm=7;
int n,m,k;
int a[maxm][maxn];
int f[maxm][maxn][20];

int ans,ansx,ansy;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void build_rmq(int t){
	for (int i=1;i<=n;i++) f[t][i][0]=a[t][i];
	for (int j=1;j<=log2(n);j++)
		for (int i=1;i<=n-(1<<j)+1;i++)
			f[t][i][j]=max(f[t][i][j-1],f[t][i+(1<<(j-1))][j-1]);
}

inline int find_rmq(int t,int l,int r){
	int up=log2(r-l+1);
	return max(f[t][l][up],f[t][r-(1<<up)+1][up]);
}

inline bool check(int l,int r){
	int cnt=0;
	for (int i=1;i<=m;i++) cnt+=find_rmq(i,l,r);
	// printf("[%lld %lld] : %lld\n",l,r,cnt);
	return cnt<=k;
}

signed main(){
	n=read();m=read();k=read();
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) a[j][i]=read();
	}
	for (int t=1;t<=m;t++) build_rmq(t);

	for (int i=1;i<=n;i++){
		int L=i,R=n;
		while (L<=R){
			int mid=((R-L)>>1)+L;
			if (check(i,mid)){
				if (mid-i+1>ans) ans=mid-i+1,ansx=i,ansy=mid;
				L=mid+1;
			} else R=mid-1;
		}
	}

	for (int i=1;i<=m;i++) printf("%lld ",find_rmq(i,ansx,ansy));
	printf("\n");
	return 0;
}