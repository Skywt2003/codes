#include<bits/stdc++.h>

using namespace std;
#define int long long

const int maxn=10,maxm=10,maxnum=25;
int n,m;

signed main(){
	srand(time(NULL));
	n=rand()%maxn+1;
	m=rand()%maxm+1;
	printf("%lld %lld %lld %lld\n",n,m,(int)1,n);
	for (int i=1;i<=n;i++) printf("%lld ",rand()%maxnum);printf("\n");
	for (int i=1;i<=m;i++){
		int x=rand()%n+1,y=rand()%n+1;
		if (x>y) swap(x,y);
		printf("%lld %lld\n",x,y);
	}
	return 0;
}