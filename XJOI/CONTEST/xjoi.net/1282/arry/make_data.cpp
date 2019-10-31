#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

int n=5,k;

bool vis[maxn];
int a[maxn];

signed main(){
	srand(time(NULL));

	n=5; k=rand()%(n*(n-1)/2+1);
	printf("%d %d\n",n,k);
	for (int i=1;i<=n;i++) a[i]=i;
	random_shuffle(a+1,a+1+n);
	for (int i=1;i<=n;i++) printf("%d ",a[i]); printf("\n");

	random_shuffle(a+1,a+1+n);
	for (int i=1;i<=n;i++) printf("%d ",a[i]); printf("\n");
	return 0;
}