#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const long long maxn=100005,tt=1e9+7;
long long n,cnt=0,fact[maxn],inv[maxn];

// sum_{k=1}^{n} C_{n}^{k} C_{n-1}^{k-1}

inline void build_inverse(){
	inv[0]=1;inv[1]=1;
	for (long long i=2;i<=n;i++) inv[i]=(tt-tt/i)*inv[tt%i]%tt;
	for(long long i=1;i<=n;i++) inv[i]=inv[i-1]*inv[i]%tt;
}

inline void build_fact(){
	fact[0]=1;
	for (long long i=1;i<=n;i++) fact[i]=i*fact[i-1]%tt;
}

// inline void init(long long n=1e5){
// 	fact[0]=1;
// 	for(long long i=1;i<=n;i++) fact[i]=i*fact[i-1]%tt;
// 	inv[1]=1;
// 	for(long long i=2;i<=n;i++) inv[i]=tt-(tt/i)*inv[tt%i]%tt;
// 	inv[0]=1;
// 	for(long long i=1;i<=n;i++) inv[i]=inv[i-1]*inv[i]%tt;
// }

inline long long C(long long x,long long y){ // C(n,m)=n!/(n-m)!m!
	// printf("C(%d,%d): %d\n",x,y,fact[x]*inv[x-y]%tt*inv[y]%tt);
	return fact[x]*inv[x-y]%tt*inv[y]%tt;
}

int main(){
	scanf("%lld",&n);
	build_inverse();
	build_fact();
	// init();
	for (long long i=1;i<=n;i++) cnt=(cnt+C(n,i)*C(n-1,i-1)%tt)%tt;
	printf("%lld\n",(cnt*2%tt-n+tt)%tt);
	return 0;
}