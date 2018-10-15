#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=2005;
int n;
bool vis[maxn];
inline void prime(){
	memset(vis,1,sizeof(vis));
	vis[1]=0;
	for (int i=2;i<=sqrt(n)+1;i++)
	for (int j=2;j<=n/i;j++)
		if (vis[i*j]) vis[i*j]=0;
}
int main(){
	scanf("%d",&n);
	prime();
	for (int i=1;i<=n;i++) if (vis[i]) printf("%d ",i);
	printf("\n");
	return 0;
}
