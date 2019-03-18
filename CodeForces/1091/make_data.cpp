#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
	srand(time(NULL));
	int n=500000;
	printf("%lld\n",n);
	for (int i=1;i<=n;i++) if (rand()&1) printf("500000 "); else printf("300000 ");
	return 0;
}