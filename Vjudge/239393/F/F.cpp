/*
 * Vjudge CONTEST 239393
 * F - Mondriaan's Dream
 * 181027 By SkyWT
 */

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;
#define int long long

#define memset_clear(_) memset(_,0,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl;


namespace FastIO{
	int read(){
		int ret=0,f=1;char ch=getchar();
		while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
		while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
		return ret*f;
	}
}

const int maxn=15,maxs=2048+20;
int n,m,s;

namespace DP{
	int h,f[2][maxs];

	inline void init(){
		memset_clear(f);
		s=1<<m;h=1<<(m-1);
	}

	inline void solve(){
		if ((n&1)&&(m&1)) return;
		f[0][s-1]=1;int now=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				now^=1;memset(f[now],0,sizeof(f[now]));
				for (int k=0;k<s;k++) if (k&h){
					f[now][(k^h)<<1]+=f[now^1][k];
					if (j!=0 && !(k&1)) f[now][((k^h)<<1)|3]+=f[now^1][k];
				} else  if (i!=0) f[now][((k&(h-1))<<1)|1]+=f[now^1][k];
			}
		}
	}
}

signed main(){
	n=FastIO::read();m=FastIO::read();
	while (n||m){
		DP::init();
		DP::solve();
		printf("%lld\n",DP::f[n*m&1][s-1]);
		n=FastIO::read();m=FastIO::read();
	}
	return 0;
}