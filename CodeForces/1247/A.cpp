#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int x,y;

signed main(){
	x=read(),y=read();
	if (x==y) printf("%lld8 %lld9\n",x,y); else
	if (y==x+1) printf("%lld9 %lld0\n",x,y); else
	if (x==9 && y==1) printf("%lld9 %lld00\n",x,y); else
	printf("-1\n");
	return 0;
}