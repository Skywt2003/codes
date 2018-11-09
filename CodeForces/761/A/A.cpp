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

signed main(){
	int x=read(),y=read();
	if (x==0 && y==0) printf("NO\n"); else
	if (x==y+1 || x+1==y || x==y) printf("YES\n"); else printf("NO\n");
	return 0;
}