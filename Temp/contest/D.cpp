#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

#define int long long
const int tt=998244353;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;
int n,ans=0;

inline int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt;b>>=1;
	}
	return ret;
}

inline int fact(int x){
	int ret=1;
	for (int i=3;i<=x;i++) ret=ret*i%tt;
	return ret;
}

signed main(){
	n=read();
	if (n==3){
		printf("9\n");
		return 0;
	}
	int w=(fact(n)-1+tt)%tt;
	// int w=(n*fact(n) - (n-1))/(2*n);
	ans=(w*n%tt + n%tt)%tt;
	int xx=3;
	for (int i=4;i<=n;i++){
		// cout<<w-(w+1)/xx+1 <<endl;
		ans=(ans+w-(w+1)*qsm(xx,tt-2)%tt+1+tt)%tt;
		xx=xx*i%tt;
		// cout<<xx<<endl;
	}

	printf("%lld\n",ans);
	return 0;
}