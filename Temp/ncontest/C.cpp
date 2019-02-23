#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

double h,r;
int ans=0;

signed main(){
	r=read();h=read();
	ans=(h+r/2.0)/r*2.0;
	double tmp=(sqrt(3)-1.0)/2.0*r;
	ans=max(ans,2*(int)((h+r/2.0-tmp)/r)+1);
	printf("%lld\n",ans);
	return 0;
}