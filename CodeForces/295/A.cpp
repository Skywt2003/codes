#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005;

int n,m,k;
int f[maxn],a[maxn];
int l[maxn],r[maxn],d[maxn];
int ff[maxn];

signed main(){
	n=read();m=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) l[i]=read(),r[i]=read(),d[i]=read();
	for (int i=1;i<=k;i++){
		int x=read(),y=read();
		f[x]++;f[y+1]--;
	}
	int count=0;
	for (int i=1;i<=m;i++){
		count+=f[i];
		ff[l[i]]+=count*d[i];
		ff[r[i]+1]-=count*d[i];
	}
	int delta=0;
	for (int i=1;i<=n;i++){
		delta+=ff[i];
		printf("%lld ",a[i]+delta);
	}
	printf("\n");
	return 0;
}