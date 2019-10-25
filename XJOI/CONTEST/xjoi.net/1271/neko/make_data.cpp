#include<bits/stdc++.h>

using namespace std;

int T=5;
int n=6,s,m,k;

signed main(){
	srand(time(NULL));
	printf("%d\n",T);
	while (T--){
		s=rand()%30; m=rand()%7+1; k=rand()%n;
		printf("%d %d %d %d\n",n,s,m,k);
		for (int i=0;i<n;i++) printf("%d ",(((rand()-rand())&1)?1:-1)*rand()%10); printf("\n");
	}

	return 0;
}