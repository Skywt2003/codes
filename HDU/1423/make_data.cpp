#include<cstdio>
#include<cstring>
#include<iostream>
#include<Windows.h>
using namespace std;
const int maxn=500,maxx=1000000;
int t,n;
inline int random(int x){
	return ((rand()<<15)+(rand()<<1)+(rand()&1))%x;
}
int main(){
	srand(GetTickCount());
	freopen("lics.in","w",stdout);
	t=random(5)+1;
	printf("%d\n",t);
	for (int j=1;j<=t;j++){
		n=random(maxn-1)+1;
		printf("%d\n",n);
		for (int i=1;i<=n;i++) printf("%d ",random(maxx-1)+1);
		printf("\n");
		n=random(maxn)+1;
		printf("%d\n",n);
		for (int i=1;i<=n;i++) printf("%d ",random(maxx-1)+1);
		printf("\n");
	}
	return 0;
}
