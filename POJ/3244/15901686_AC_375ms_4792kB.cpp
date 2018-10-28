#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const long long maxn=200005;
long long n,a[maxn],b[maxn],c[maxn];
long long ans=0;

int main(){
	for (;;){
		scanf("%lld",&n);
		if (n==0) break;
		ans=0;

		for (long long i=1;i<=n;i++){
			long long x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			a[i]=x-y,b[i]=y-z,c[i]=z-x;
		}
		sort(a+1,a+1+n);sort(b+1,b+1+n);sort(c+1,c+1+n);

		long long sum_a=0,sum_b=0,sum_c=0;
		for (long long i=1;i<=n;i++){
			ans+=a[i]*(i-1)-sum_a;
			ans+=b[i]*(i-1)-sum_b;
			ans+=c[i]*(i-1)-sum_c;
			sum_a+=a[i];sum_b+=b[i];sum_c+=c[i];
		}
		printf("%lld\n",ans/2);
	}
	return 0;
}