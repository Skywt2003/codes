#include<bits/stdc++.h>
using namespace std;
// #define int long long

const int maxn=11,logmaxn=2;
int n,a[maxn];

namespace RMQ{
	int f[maxn][logmaxn];

	inline void build_rmq(){
		for (int i=1;i<=n;i++) f[i][0]=a[i];
		for (int j=1;j<=log2(n);j++)
			for (int i=1;i<=n-(1<<j)+1;i++)
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}

	inline int find_rmq(int l,int r){
		int up=log2(r-l+1);
		return max(f[l][up],f[r-(1<<up)+1][up]);
	}
}