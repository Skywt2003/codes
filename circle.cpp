#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

#define sqr(_) ((_)*(_))
#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))

const long long maxn=1e6+5;
long long n,ans=0;
long long py[maxn]; // py[i]: (prime yinzi) i 的最小质因子
vector<long long> p;

inline long long make_prime_yinzi(long long x){
	p.clear();
	while (x>1){
		long long i=py[x];
		if (x%i==0) p.push_back(i);
		while (x%i==0) x/=i;
	}
}

inline void build_prime_yinzi(){
	memset_clear_reg(py);
	for (long long i=2;i<=n;i++) if (py[i]==-1)
		for (long long j=i;j<=n;j+=i) if (py[j]==-1) py[j]=i;
}

inline long long make(long long x,long long y){
	long long ret=0;
	make_prime_yinzi(x);
	long long s=1<<p.size();
	long long nn=p.size();
	for (long long i=0;i<s;i++){
		long long now=1,cnt=1;
		for (long long j=0;j<nn;j++) if (i&(1<<j)) now=now*p[j],cnt=-cnt;
		ret+=cnt*y/now;
	}
	return ret;
}

int main(){
	scanf("%lld",&n);
	build_prime_yinzi();
	long long now_y=n;
	for (long long i=1;i<=n;i++){
		long long lmt_y=sqr(n)-sqr(i);
		while (sqr(now_y)>lmt_y) now_y--;
		ans+=make(i,now_y);
	}
	printf("%lld\n",ans*4+4);
	return 0;
}