#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,m,k,cnt,nxt[maxn],lst[maxn];
bool vis[maxn];
int main(){
	scanf("%d%d%d",&n,&k,&m);
	cnt=n;memset(vis,1,sizeof(vis));
	for (int i=0;i<n;i++) nxt[i]=i+1,lst[i]=i-1;
	nxt[n-1]=0;lst[0]=n-1;
	int now=lst[k];
	while (cnt>1){
		for (int i=1;i<=m;i++) now=nxt[now];
		vis[now]=0;nxt[lst[now]]=nxt[now];lst[nxt[now]]=lst[now];cnt--;
	}
	for (int i=0;i<n;i++) if (vis[i]){
		printf("%d\n",i);
		return 0;
	}
	return 0;
}
