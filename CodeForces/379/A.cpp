#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,m,ans=0;

signed main(){
	n=read();m=read();
	int now=0;
	while (n){
		ans+=n;
		now+=n;n=0;
		n=now/m;now%=m;
	}
	printf("%lld\n",ans);
	return 0;
}