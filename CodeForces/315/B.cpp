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

const int maxn=1e5+5;
int n,m,a[maxn];

signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int delta=0;
	for (int i=1;i<=m;i++){
		int cmd=read();
		if (cmd==1){
			int x=read(),y=read();
			a[x]=y-delta;
		} else if (cmd==2){
			int x=read();
			delta+=x;
		} else if (cmd==3){
			int x=read();
			printf("%lld\n",a[x]+delta);
		}
	}
	return 0;
}