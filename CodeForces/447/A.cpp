#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int n,p;
bool vis[305];

int main(){
	scanf("%d%d",&p,&n);
	int x;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (vis[x%p]){
			printf("%d\n",i);
			return 0;
		} else vis[x%p]=true;
	}
	printf("-1\n");
	return 0;
}
