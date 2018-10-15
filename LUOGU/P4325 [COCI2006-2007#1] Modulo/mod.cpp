#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=50,tt=42;
int ans=0;
bool vis[maxn];
int main(){
	int x;
	for (int i=0;i<10;i++){
		scanf("%d",&x);
		vis[x%tt]=1;
	}
	for (int i=0;i<tt;i++) if (vis[i]) ans++;
	printf("%d\n",ans);
	return 0;
}
