#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long maxn=305,tt=1e9+7;
long long n,ans=0;

#define sqr(_) ((_)*(_))

inline long long read(){
	long long ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}

int main(){
	n=read();
	ans=2*sqr(n)-n;
	for (long long down=2;sqr(down)<=n;down++)
	for (long long x=down,a=1;x<=n;x*=down,a++)
	for (long long y=down,b=1;y<=n;y*=down,b++){
		if (gcd(a,b)==1&&a!=b) ans=(ans+n/max(a,b))%tt;
	}
	printf("%lld\n",ans);
	return 0;
}