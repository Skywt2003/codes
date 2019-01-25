#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;
set<int> ans;
set<int>::iterator it;

signed main(){
	n=read();
	ans.clear();
	ans.insert(1);
	ans.insert((1+n)*n/2);
	int up=sqrt(n)+1;
	for (int i=2;i<=up;i++) if (n%i==0){
		int k=i;
		ans.insert((1+n-k+1)*(n/k)/2);
		k=n/i;
		ans.insert((1+n-k+1)*(n/k)/2);
	}
	for (it=ans.begin();it!=ans.end();it++) printf("%lld ",*it);
	printf("\n");
	return 0;
}