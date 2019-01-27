#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define int long long

const int maxn=100005;
int n;
int a[maxn];
bool vis[maxn];
int lft[maxn],rght[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int ans=min(n,(int)2);
	memset(lft,-1,sizeof(lft));
	memset(vis,0,sizeof(vis));
	for (int i=2;i<=n;i++){
		if (a[i]>a[i-1]){
			if (vis[i-1]==false) lft[i-1]=lft[i]=i-1; else lft[i]=lft[i-1];
			vis[i-1]=vis[i]=true;
			ans=max(ans,i-lft[i]+2);
		}
	}
	memset(rght,-1,sizeof(rght));
	memset(vis,0,sizeof(vis));
	for (int i=n-1;i>=1;i--){
		if (a[i]<a[i+1]){
			if (vis[i+1]==false) rght[i+1]=rght[i]=i+1; else rght[i]=rght[i+1];
			vis[i+1]=vis[i]=true;
		}
	}
	if (lft[n]==1 && rght[1]==n){
		printf("%lld\n",n);
		return 0;
	}
	for (int i=2;i<n;i++) if (vis[i-1] && vis[i+1] && a[i-1]<a[i+1]-1){
		if (lft[i-1]==-1 || rght[i+1]==-1) continue;
		ans=max(ans,rght[i+1]-lft[i-1]+1);
	}
	printf("%lld\n",ans);
	return 0;
}