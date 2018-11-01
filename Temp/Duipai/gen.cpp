#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn=10,maxm=20;

int n,m;

signed main(){
	puts("1\n");
	srand(time(NULL));
	n=rand()%maxn+1,m=rand()%maxm+1;
	printf("%lld %lld\n",n,m);
	for (int i=0;i<n;i++) printf("%lld ",(int)rand()%2);printf("\n");
	for (int i=0;i<m;i++){
		int x=rand()%n;
		int y=rand()%n;
		printf("%lld %lld\n",x,y);
	}
	return 0;
}
