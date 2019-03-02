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

int t,n,p;

signed main(){
	t=read();
	while (t--){
		n=read();p=read();
		int x=1,y=2;
		for (int i=1;i<=n*2+p;i++){
			printf("%lld %lld\n",x,y);
			if (++y==n+1) x++,y=x+1;
		}
	}
}
