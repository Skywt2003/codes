#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int no[3][3]={{-1,2,1},{2,-1,0},{1,0,-1}};
int n,tot=0;
inline void dfs(int x,int y,int s){
	if (s==1){
		printf("%d->%d\n",x,y);tot++;
		return;
	}
	dfs(x,no[x-1][y-1]+1,s-1);
	printf("%d->%d\n",x,y);tot++;
	dfs(no[x-1][y-1]+1,y,s-1);
}
int main(){
	scanf("%d",&n);
	dfs(1,3,n);
	printf("tot=%d\n",tot);
	return 0;
}
