#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,a,b,p,q;
long long ans=0;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline int gcd(int x,int y){
	if (y==0) return x;
	return gcd(y,x%y);
}
int main(){
	n=read();a=read();b=read();p=read();q=read();
	ans+=(long long)p*(int)(n/a)+(long long)q*(int)(n/b);
	int sub=-min(p,q);
	long long lcm=(long long)a*b/gcd(a,b);
	ans=ans+(long long)sub*(n/lcm);
	printf("%lld\n",ans);
	return 0;
}
