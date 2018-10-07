#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a,b;
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
	n=read();m=read();a=read();b=read();
	long long g=gcd(a,b);
	a/=g;b/=g;
	cout<<min(n/a,m/b)<<endl;
	return 0;
}