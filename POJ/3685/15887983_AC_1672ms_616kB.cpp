#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const long long maxn=50005;
long long T,n,m;

inline long long get_num(long long i,long long j){
	return (long long)i*i+(long long)j*j+(long long)100000*i-(long long)100000*j+(long long)i*j;
}

inline void print_matrix(long long n){
	for (long long i=1;i<=n;i++){
		for (long long j=1;j<=n;j++) printf("%lld ",get_num(i,j));
		printf("\n");
	}
}

inline bool check(long long now){
	long long sum=0;
	for (long long j=1;j<=n;j++){
		long long L=1,R=n;
		long long now_sum=0;
		while (L<=R){
			long long mid=((R-L)>>1)+L;
			if (get_num(mid,j)<=now) now_sum=mid,L=mid+1; else R=mid-1;
		}
		sum+=now_sum;
		if (sum>m) return false;
	}
	return sum<m;
}

int main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld",&n,&m);
		long long L=-200000*n,R=3*n*n+100000*n,ans=0;
		while (L+1<R){
			long long mid=((R-L)>>1)+L;
			if (check(mid)) ans=mid,L=mid; else R=mid;
		}
		printf("%lld\n",ans+1);
	}
	return 0;
}