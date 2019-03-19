#include<bits/stdc++.h>

using namespace std;
#define int long long

const int n=10;
const int maxnum=100;

signed main(){
	srand(time(NULL));
	printf("%lld\n",n*2);
	printf("1 -1\n1 10000\n");
	for (int i=3;i<=n;i++) printf("1 %lld\n",rand()%maxnum);
	for (int i=1;i<=n;i++) printf("%lld %lld\n",rand()%4+3,rand()%(n-1)+1);
	return 0;
}