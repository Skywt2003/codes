#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

#define int long long
using namespace std;

int a,p,q,k;
int b,l,m,c;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int qsm(int a,int b){
	int ret=1,w=a%p;
	while (b){
		if (b&1) ret=(ret*w)%p;
		b>>=1;w=w*w%p;
	}
	return ret;
}

signed main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	a=read();p=read();q=read();k=read();
	b=read();l=read();m=read();c=read();
	int x=0;
	for (int i=1;i<=q;i++){
		b=(m*b+c)%l;
		x^=qsm(a,b);
		if (i%k==0) printf("%lld\n",x);
	}
	return 0;
}