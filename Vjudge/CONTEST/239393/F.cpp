/*
 * Vjudge CONTEST 239393
 * F - Mondriaan's Dream
 * 181014 By SkyWT
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

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl;

#define int long long

namespace FastIO{
	int read(){
		int ret=0,f=1;char ch=getchar();
		while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
		while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
		return ret*f;
	}
}

const int maxn=15,maxs=2048+20;
int n,m,s,f[2][maxs];

namespace DP{
	void init(){
		memset_clear(f);
		s=1<<m;
	}
	void make_answer(){
		if ((n&1)&&(m&1)) return;
		f[1][0]=1;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				memset_clear(f[i&1]);
				for (int k=0;k<s;k++){
					
				}
			}
		}
	}
	int get_answer(){

	}
}

signed main(){
	n=FastIO::read();m=FastIO::read();
	while (n||m){
		DP::init();
		DP::make_answer();
		printf("%lld\n",DP::get_answer());
		n=FastIO::read();m=FastIO::read();
	}
	return 0;
}