#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define write(_) cout<<#_<<" = "<<_<<endl
#define write2(_,__) cout<<#_<<" = "<<_<<", "<<#__<<" = "<<__<<endl

using namespace std;
const long long maxn=1e7+5,tt=998244353;
long long N;
long long L,R,delta,ans1=0,ans2=0;
bool flg[maxn],vis[maxn];
vector<long long> prime;

inline void make_prime(){
	prime.clear();
	for (long long i=2;i<=N;i++){
		if (!flg[i]){
			prime.push_back(i);
			for (long long k=(L+i-1)/i*i;k<=R;k+=i) if ((!vis[k-delta])&&(i!=k)) ans1++,ans2=(ans2+i)%tt,vis[k-delta]=true;
		}
		for (long long j=0;j<prime.size()&&i*prime[j]<=N;j++){
			flg[i*prime[j]]=true;
			if (i%prime[j]==0) break;
		}
	}
}

int main(){
	scanf("%lld%lld",&L,&R);delta=L-1;
	N=sqrt(R+0.5);
	make_prime();
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}