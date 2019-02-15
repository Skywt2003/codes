#include<bits/stdc++.h>

const int maxn=1e5,maxx=1e9;

// int random(int x){
// 	return ((rand()<<15)+(rand()<<1)+(rand()&1))%x;
// }

int random(int x){
	return rand()%x;
}

int main(){
	srand(time(NULL));
	printf("%d %d\n",maxn,maxn);
	for (int i=1;i<=maxn;i++) printf("%d %d %d\n",random(maxx),random(maxx),random(maxx));
	for (int i=1;i<=maxn;i++) printf("%d %d %d\n",random(maxx),random(maxx),random(maxx));
	return 0;
}