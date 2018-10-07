#include <cstdio>
typedef long long LL;
const LL mod = 19260817;
const LL M = 13;
inline LL qsm(LL a,int b){
	LL ret=1,w=a%M;
	while (b){
		if (b&1) ret=ret*w%M;
		w=w*w%M;b>>=1;
	}
	return ret;
}
int main() {
	printf("%lld\n", qsm(6 ,11));
	LL a, b;
	printf("%lld, H=%d\n", 6594737 % 31, 'H' - 'A');
	while (~scanf("%lld%lld", &a, &b)) printf("a*b%%mod=%lld\n", a * b % mod);
	return 0;
}