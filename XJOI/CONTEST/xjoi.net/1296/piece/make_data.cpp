#include<bits/stdc++.h>

using namespace std;

const int maxk=500000;
const int maxx=1000000;

int n=1000,k;

signed main(){
	srand(time(NULL));
	k=rand()%maxk+5;
	
	printf("%d %d\n",n,k);
	for (int i=1;i<=n;i++) printf("%d ",rand()%maxx+1);
	printf("\n");
	return 0;
}
