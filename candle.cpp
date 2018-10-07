#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;
 
#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))
 
#define int long long
 
const int maxn=100005;
int n,m;
int a[maxn];
 
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
 
signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (a[n]<0){
		for (int i=1;i<=n/2;i++) a[i]=-a[i],a[n-i+1]=-a[n-i+1],swap(a[i],a[n-i+1]);
	}
	int ans=(long long)1<<60;
	int x=0;
	if (x<a[1]) x=1; else
	if (x>a[n]) x=n; else
	for (int i=1;i<n;i++)
		if (a[i]<x && x<=a[i+1]) {x=i+1;break;}
	for (int i=x;i<=min(n,x+m-1);i++) if (i-m+1>0){
		if (a[i-m+1]<0){
			ans=min(ans,a[i]*2-a[i-m+1]);
			ans=min(ans,a[i]-a[i-m+1]*2);
		} else if (i>=m) ans=min(ans,a[i]);
	}
	if (ans==((int)1<<60)) printf("0\n"); else printf("%lld\n",ans);
	return 0;
}