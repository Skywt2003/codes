#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

#define int long long
using namespace std;

const int maxn=55,maxt=1e5+5;
int n,T;
int a[maxn],b[maxn],t[maxn];
int f[maxt];
vector<int> opt[maxt];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

struct problem{
	int a,b,t;
}p[maxn];

signed main(){
	n=read();T=read();
	for (int i=1;i<=n;i++) p[i].a=read();
	for (int i=1;i<=n;i++) p[i].b=read();
	for (int i=1;i<=n;i++) p[i].t=read();

	for (int i=1;i<=n;i++){
		for (int j=T;j>=p[i].t;j++){
			vector now=opt[i];
			
		}
	}

	int ans=0;
	for (int i=0;i<=T;i++) ans=max(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}