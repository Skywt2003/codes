#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,m;
vector<int> a,b;

signed main(){
	n=read();m=read();
	a.clear();b.clear();
	int up = 1;
	while (up * (up + 1)/2 <= n + m) ++ up;
	for (int i=up-1;i>=1;i--){
		if (i<=n) a.push_back(i),n-=i; else
		if (i<=m) b.push_back(i),m-=i;
	}
	printf("%lld\n",(int)a.size());
	for (int i=0;i<(int)a.size()-1;i++) printf("%lld ",a[i]);
	if ((int)a.size()>0) printf("%lld\n",a[a.size()-1]); else printf("\n");
	printf("%lld\n",(int)b.size());
	for (int i=0;i<(int)b.size()-1;i++) printf("%lld ",b[i]);
	if ((int)b.size()>0) printf("%lld\n",b[b.size()-1]); else printf("\n");
	return 0;
}