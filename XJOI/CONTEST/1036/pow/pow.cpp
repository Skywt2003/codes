#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

#define int long long
using namespace std;

const int maxn=1e6+10,N=1e6;

int a,p,q,k;
int b,l,m,c;
int p1[maxn],p2[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void build(){
	p1[0]=1;
	for (int i=1;i<N;i++) p1[i]=p1[i-1]*a%p;
	p2[0]=1;
	for (int i=1;i<N;i++) p2[i]=p2[i-1]*p1[N-1]%p*a%p;
}

signed main(){
	a=read();p=read();q=read();k=read();
	b=read();l=read();m=read();c=read();
	build();
	int x=0;
	for (int i=1;i<=q;i++){
		b=(m*b+c)%l;
		x^=p1[b%N]*p2[b/N]%p;
		if (i%k==0) printf("%lld\n",x);
	}
	return 0;
}