#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const long long tt=100003;
long long m=0,n=0,ans=0;
inline long long llread(){
	long long ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=(long long)ret*10+(long long)(ch-'0'),ch=getchar();
	return (long long)ret*f;
}
inline long long qsm(long long a,long long b){
	long long w=a,ret=1;
	while (b){
		if (b&1) ret=(ret*w)%tt;
		b>>=1;
		w=(long long)(w*w)%tt;
	}
	return ret;
}
int main(){
	freopen("prison.in","r",stdin);
	freopen("prison.out","w",stdout);
	m=llread();n=llread();
	ans=((long long)qsm(m,n)-(long long)(m%tt)*(long long)qsm(m-1,n-1))%tt;
	printf("%lld\n",(ans+tt)%tt);
	return 0;
}
