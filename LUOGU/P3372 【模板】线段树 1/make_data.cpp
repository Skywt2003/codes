#include<cstdio>
#include<cstring>
#include<iostream>
#include<windows.h>
#include<algorithm>
using namespace std;
const int maxn=10,maxm=10,maxk=200;
int n,m;
inline int random(int x){
	return ((rand()<<15)+(rand()<<1)+(rand()&1))%x;
}
int main(){
	srand(GetTickCount());
	freopen("tree.in","w",stdout);
	n=random(maxn)+1;m=random(maxm)+1;
	printf("%d %d\n",n,m);
	for (int i=1;i<=n;i++) printf("%d ",random(maxk));printf("\n");
	for (int i=1;i<=m;i++){
		int x=random(2)+1;printf("%d ",x);
		if (x==1){
			int sl=random(n)+1,sr=random(n)+1;
			if (sl>sr) swap(sl,sr);
			printf("%d %d %d\n",sl,sr,random(maxk));
		} else if (x==2){
			int sl=random(n)+1,sr=random(n)+1;
			if (sl>sr) swap(sl,sr);
			printf("%d %d\n",sl,sr);
		}
	}
	return 0;
}
