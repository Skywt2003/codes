#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	int a=read(),b=read(),k=read();
	int ans=0;
	for (int i=1;i<=k;i++){
		ans+=2*a+2*b-4;
		a-=4;b-=4;
	}

	printf("%lld\n",ans);
	return 0;
}