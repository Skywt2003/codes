#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3005,maxe=6005;
int n,m;
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
int s1,t1,s2,t2,m1,m2;

signed main(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		
	}
}