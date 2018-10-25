#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=15,maxs=1024+10;
int n,a[maxn];
int f[maxn][maxs][2];

inline void init(){
	
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	init();
}