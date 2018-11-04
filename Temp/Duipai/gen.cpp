#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn=10,maxx=10;

int n,m;

signed main(){
	puts("1\n");
	srand(time(NULL));
	n=rand()%maxn+1;
	printf("%lld\n",n);
	for (int i=0;i<n;i++) printf("%lld ",(int)rand()%maxx);printf("\n");
	return 0;
}
