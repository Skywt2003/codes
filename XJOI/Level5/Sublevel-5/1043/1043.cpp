#include<cstdio>
#include<cstring>
#include<iostream>

#define int long long
using namespace std;

const int maxn=105;
int n;
int ls[maxn],rs[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		int t=read();
		if (t==0) continue;
		int x=read(),lst;t--;
		ls[i]=lst=x;
		while (t--){
			int x=read();
			rs[lst]=x;
			lst=x;
		}
	}
	printf("%lld\n",n);
	for (int i=1;i<=n;i++) printf("%lld %lld\n",ls[i],rs[i]);
	return 0;
}