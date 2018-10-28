#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int T;
long long a,b,L;
inline long long read(){
	long long ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=(long long)ret*10+(long long)(ch-'0'),ch=getchar();
	return ret*f;
}
inline long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
inline long long qsm(long long a,int b){
	long long ret=1,w=a;
	while (b){
		if (b&1) ret=ret*w;
		b>>=1;w=w*w;
	}
	return ret;
}
int main(){
	T=read();
	for (int t=1;t<=T;t++){
		a=read();b=read();L=read();
		long long c=a/gcd(a,b)*b;
		if (L%c) {printf("Case %d: impossible\n",t);continue;}
		long long ans=L/c; // Let lcm(ans,c)=L
		for (long long i=2;i<=c;i++) if (!(c%i)){
			long long now=1;int cnt1=0,cnt2=0;
			while (!(c%i)) now=now*i,c/=i,cnt1++;
			long long nowL=L;
			while (!(nowL%i)) nowL/=i,cnt2++;
			if (cnt1==cnt2) continue;
			ans=ans*now;
		}
		printf("Case %d: %lld\n",t,ans);
	}
	return 0;
}